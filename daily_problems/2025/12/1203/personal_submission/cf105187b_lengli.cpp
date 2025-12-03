#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> t;

    Fenwick(int n): n(n), t(n + 1, 0) {}

    // add value at index i
    void add(int i, int v) {
        for (++i; i <= n; i += i & -i) t[i] += v;
    }

    // sum of [0..i]
    int sum(int i) {
        if (i < 0) return 0;
        if (i >= n) i = n - 1;
        int r = 0;
        for (++i; i > 0; i -= i & -i) r += t[i];
        return r;
    }

    // sum of [l..r]
    int range_sum(int l, int r) {
        if (r < l) return 0;
        return sum(r) - sum(l - 1);
    }
};

static inline int calc_v(int x, int y) {
    return min(max(x + 1, y + 1), max(x + 3, y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(2 * n);
    for (int &x : nums) cin >> x;

    vector<pair<int,int>> cmp(n);
    for (auto &[u, v] : cmp) cin >> u >> v;

    const int M = 500000 + 100;
    Fenwick fen(M);

    // ---- helper lambdas ----
    auto add_pair = [&](int u, int v, int val) {
        int x = nums[u], y = nums[v];
        if (x > y) swap(x, y);
        fen.add(x, val);
        fen.add(calc_v(x, y), val);
    };

    auto calc_ans = [&](int i) {
        return 2 * n - fen.range_sum(0, nums[i] + 3);
    };

    // ---- initial add ----
    for (auto &[u, v] : cmp) add_pair(u, v, 1);

    vector<int> ans(2 * n);

    // ---- main loop ----
    for (auto &[u, v] : cmp) {
        add_pair(u, v, -1);

        ans[u] = calc_ans(u);
        ans[v] = calc_ans(v);

        if (nums[u] + 3 >= nums[v]) ans[u]--;
        if (nums[v] + 3 >= nums[u]) ans[v]--;

        add_pair(u, v, 1);
    }

    for (int x : ans) cout << x << ' ';
}
