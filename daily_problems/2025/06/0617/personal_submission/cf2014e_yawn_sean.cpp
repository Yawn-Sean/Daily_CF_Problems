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

    int t;
    cin >> t;
    long long inf = 1e13;

    while (t --) {
        int n, m, h;
        cin >> n >> m >> h;

        vector<bool> horses(n, 0);
        while (h --) {
            int p;
            cin >> p;
            horses[p - 1] = 1;
        }

        vector<vector<pair<int, int>>> path(n);
        while (m --) {
            int u, v, w;
            cin >> u >> v >> w;
            u --, v --;
            path[u].emplace_back(v, w);
            path[v].emplace_back(u, w);
        }

        vector<long long> d1(2 * n, inf);
        d1[0] = 0;

        priority_queue<pair<long long, int>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            d = -d;
            if (d1[u] == d) {
                bool flg = false;
                if (u >= n) {
                    u -= n;
                    flg = true;
                }
                else if (horses[u])
                    flg = true;

                for (auto &[v, w]: path[u]) {
                    int nv;
                    long long nd;
                    if (flg) {
                        nv = v + n;
                        nd = d + w / 2;
                    }
                    else {
                        nv = v;
                        nd = d + w;
                    }
                    if (nd < d1[nv]) {
                        d1[nv] = nd;
                        pq.push({-nd, nv});
                    }
                }
            }
        }

        vector<long long> d2(2 * n, inf);
        d2[n - 1] = 0;

        pq.push({0, n - 1});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            d = -d;
            if (d2[u] == d) {
                bool flg = false;
                if (u >= n) {
                    u -= n;
                    flg = true;
                }
                else if (horses[u])
                    flg = true;

                for (auto &[v, w]: path[u]) {
                    int nv;
                    long long nd;
                    if (flg) {
                        nv = v + n;
                        nd = d + w / 2;
                    }
                    else {
                        nv = v;
                        nd = d + w;
                    }
                    if (nd < d2[nv]) {
                        d2[nv] = nd;
                        pq.push({-nd, nv});
                    }
                }
            }
        }

        long long ans = inf;
        for (int i = 0; i < n; i ++)
            ans = min(ans, max(min(d1[i], d1[i + n]), min(d2[i], d2[i + n])));
        cout << (ans < inf ? ans : -1) << '\n';
    }

    return 0;
}