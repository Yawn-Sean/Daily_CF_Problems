#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;
i64 inf = 1e18;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void init(const std::vector<T> &v) {
        n = v.size();
        a.assign(n, T{});
        for (int i = 0; i < n; i++) {
            add(i, v[i]);
        }
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    /*
        z=2,3,4,5,6
        起点位置只有2(z-1)种
    */
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    vector<array<int, 4>> queries(q);
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p, v;
            cin >> p >> v;
            p--;
            queries[i] = {tp, p, v, 0};
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            --l; --r;
            queries[i] = {2, l, r, k};
        }
    }

    vector<i64> ans(q, -1);

    Fenwick<i64> fen(n);
    vector<i64> tmp(n);

    for (int z = 2; z <= 6; z++) {
        vector<int> weight(2 * z - 2);
        for (int j = 0; j < z - 1; j++) {
            weight[j] = j + 1;
        }
        for (int j = z - 1; j < 2 * z - 2; j++) {
            weight[j] = 2 * z - 1 - j;
        }

        int l = 2 * z - 2;
        for (int start = 0; start < l; start++) {
            for (int j = 0; j < n; j++) {
                tmp[j] = 1ll * a[j] * weight[(j - start + l) % l];
            }
            fen.init(tmp);

            for (int j = 0; j < q; j++) {
                if (queries[j][0] == 1) {
                    int idx = queries[j][1], val = queries[j][2];
                    fen.add(idx, 1ll * val * weight[(idx - start + l) % l] - tmp[idx]);
                    tmp[idx] = 1ll * val * weight[(idx - start + l) % l];
                } else if (queries[j][1] % l == start && queries[j][3] == z) {
                    ans[j] = fen.rangeSum(queries[j][1], queries[j][2] + 1);
                }
            }
        }
    }

    for (auto&x: ans) {
        if (x != -1) {
            cout << x << endl;
        }
    }
   
    return 0;
}
