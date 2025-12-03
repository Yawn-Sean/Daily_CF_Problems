#include <bits/stdc++.h>
using namespace std;

int mod;

// 乘法的幺元
inline int e() { return 1; }

// 乘法 merge
inline int op(int a, int b) { return 1LL * a * b % mod; }

// =========================
// ===== Hand-made SegTree =====
// =========================
struct SegTree {
    int n, size;
    vector<int> t;

    SegTree(int n) : n(n) {
        size = 1;
        while (size < n) size <<= 1;
        t.assign(2 * size, e());
    }

    // set position p to value v
    void set_val(int p, int v) {
        p += size;
        t[p] = v;
        for (p >>= 1; p >= 1; p >>= 1)
            t[p] = op(t[p << 1], t[p << 1 | 1]);
    }

    // get product over [l, r)
    int prod(int l, int r) {
        int resL = e(), resR = e();
        l += size; r += size;
        while (l < r) {
            if (l & 1) resL = op(resL, t[l++]);
            if (r & 1) resR = op(t[--r], resR);
            l >>= 1; r >>= 1;
        }
        return op(resL, resR);
    }

    // ===========================
    // max_right(l, f): 得到最大的 r，使 f( product(l, r) ) == true
    // ===========================
    template <class F>
    int max_right(int l, F f) {
        if (l == n) return n;
        int cur = e();
        int p = l + size;

        while (true) {
            // 若 p 为右子，则先跳到父亲
            while ((p & 1) == 0) p >>= 1;

            // 尝试包括当前节点
            if (!f(op(cur, t[p]))) {
                // 下钻这个节点寻找第一个失败的位置
                while (p < size) {
                    p <<= 1;
                    int nxt = op(cur, t[p]);
                    if (f(nxt)) {
                        cur = nxt;
                        p++;
                    }
                }
                return p - size;
            }

            // 可接受整个节点
            cur = op(cur, t[p]);
            p++;

            // 若 p 为其子树的根，则结束
            if ((p & -p) == p) break;
        }
        return n;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> mod >> q;

    vector<int> nums(n);
    for (int &v : nums) cin >> v;

    vector<vector<int>> child(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        child[p - 1].push_back(i);
    }

    vector<vector<pair<int, int>>> updates(n);
    for (int i = 0; i < q; i++) {
        int u, x;
        cin >> u >> x;
        updates[u - 1].push_back({i, x});
    }

    SegTree seg(q);
    vector<int> ans(n);

    function<void(int)> dfs = [&](int u) {
        // Apply updates at u
        for (auto &[i, x] : updates[u]) seg.set_val(i, x);

        int num = nums[u];
        if (num % mod == 0) {
            ans[u] = 0;
        } else {
            // find first index making product % mod == 0
            int r = seg.max_right(0, [&](int x) {
                return (1LL * x * num) % mod != 0;
            });
            ans[u] = (r == q ? -1 : r + 1);
        }

        for (int v : child[u]) dfs(v);

        // revert updates
        for (auto &[i, x] : updates[u]) seg.set_val(i, e());
    };

    dfs(0);

    for (int x : ans) cout << x << ' ';
    return 0;
}
