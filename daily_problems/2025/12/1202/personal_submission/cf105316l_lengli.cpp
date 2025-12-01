#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return (power & 1) ? base * cur % mod * cur % mod : cur * cur % mod;
}

struct Fenwick {
    int n;
    vector<long long> t;

    Fenwick(int n) : n(n), t(n + 1, 0) {}

    void add(int p, long long v) {   // 0-indexed
        for (++p; p <= n; p += p & -p) t[p] += v;
    }

    long long sumPrefix(int p) {     // 0..p
        long long r = 0;
        for (++p; p > 0; p -= p & -p) r += t[p];
        return r;
    }

    long long rsum(int l, int r) {   // [l..r]
        if (l > r) return 0;
        return sumPrefix(r) - sumPrefix(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        vector<int> nums(2 * n);
        for (auto &v: nums) cin >> v;
        vector<vector<int>> path(n + 1);
        vector<int> parent(n + 1, -1), notes(2 * n), stk = {0};
        int pt = 1;

        for (int i = 0; i < 2 * n; i++) {
            if (s[i] == '(') {
                parent[pt] = stk.back();
                path[stk.back()].push_back(pt);
                stk.push_back(pt);
                notes[i] = pt++;
            } else {
                stk.pop_back();
            }
        }

        vector<int> ls(n + 1), rs(n + 1), depth(n + 1, 0);
        int tmstamp = 0;

        auto dfs = [&](auto &self, int u) -> void {
            ls[u] = tmstamp++;
            for (int v : path[u]) {
                depth[v] = depth[u] + 1;
                self(self, v);
            }
            rs[u] = tmstamp;
        };

        dfs(dfs, 0);

        vector<vector<int>> up(20, vector<int>(n + 1, -1));
        up[0] = parent;

        for (int i = 0; i < 19; i++) {
            for (int v = 0; v <= n; v++) {
                int p = up[i][v];
                up[i + 1][v] = (p == -1 ? -1 : up[i][p]);
            }
        }

        auto lca = [&](int u, int v) -> int {
            if (depth[u] > depth[v]) swap(u, v);
            int d = depth[v] - depth[u];

            while (d) {
                int x = d & -d;
                v = up[__builtin_ctz(x)][v];
                d -= x;
            }

            if (u == v) return u;

            for (int i = 19; i >= 0; i--) {
                if (up[i][u] != up[i][v]) {
                    u = up[i][u];
                    v = up[i][v];
                }
            }
            return parent[u];
        };
        Fenwick fen(n + 1);
        while (q--) {
            int tp;
            cin >> tp;

            if (tp == 1) {
                int l1, r1, l2, r2, val;
                cin >> l1 >> r1 >> l2 >> r2 >> val;
                int u = notes[l1 - 1];
                int v = notes[l2 - 1];
                int L = lca(u, v);
                fen.add(ls[L], val);
            } else {
                int l, r;
                cin >> l >> r;
                int u = notes[l - 1];
                long long ans = fen.rsum(ls[u], rs[u] - 1) + nums[l - 1];
                cout << ans << "\n";
            }
        }
    }

    return 0;
}
