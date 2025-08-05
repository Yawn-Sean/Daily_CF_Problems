#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<long long> xs(n), ys(n);
    for (int i = 0; i < n; i ++)
        cin >> xs[i] >> ys[i];
    
    vector<int> rs(n, n - 1), depth(n, 0);
    vector<int> stk = {n - 1};

    for (int i = n - 2; i >= 0; i --) {
        while (stk.size() > 1) {
            long long x = xs[i], y = ys[i];
            long long x1 = xs[stk.back()], y1 = ys[stk.back()];
            long long x2 = xs[stk[stk.size() - 2]], y2 = ys[stk[stk.size() - 2]];

            if ((y1 - y) * (x2 - x) < (y2 - y) * (x1 - x)) stk.pop_back();
            else break;
        }

        rs[i] = stk.back();
        depth[i] = depth[stk.back()] + 1;
        stk.emplace_back(i);
    }


    vector<vector<int>> nth_parent(20, vector<int>(n));

    nth_parent[0] = rs;

    for (int i = 0; i < 19; i ++) {
        for (int j = 0; j < n; j ++) {
            nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]];
        }
    }

    int q;
    cin >> q;

    while (q --) {
        int u, v;
        cin >> u >> v;
        u --, v --;

        if (depth[u] < depth[v]) swap(u, v);

        int d = depth[u] - depth[v];

        for (int i = 19; i >= 0; i --) {
            if (d >> i & 1) {
                u = nth_parent[i][u];
            }
        }

        if (u == v) cout << u + 1 << ' ';
        else {
            for (int i = 19; i >= 0; i --) {
                if (nth_parent[i][u] != nth_parent[i][v]) {
                    u = nth_parent[i][u];
                    v = nth_parent[i][v];
                }
            }

            cout << nth_parent[0][u] + 1 << ' ';
        }
    }

    return 0;
}