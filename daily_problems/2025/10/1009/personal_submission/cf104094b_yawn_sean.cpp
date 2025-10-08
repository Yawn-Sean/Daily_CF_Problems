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

    int n, m, s, t;
    long long l;

    cin >> n >> m >> s >> t >> l;
    s --, t --;

    vector<vector<pair<int, int>>> path(n);

    while (m --) {
        int u, v, w;
        cin >> u >> v >> w;

        u --, v --;
        path[u].emplace_back(v, w);
        path[v].emplace_back(u, w);
    }

    long long inf = 1e15;
    int mod = 1e9 + 7;

    vector<long long> dis(n, inf);
    dis[t] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, t});
    vector<int> nodes;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dis[u] == d) {
            nodes.emplace_back(u);
            for (auto &[v, w]: path[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
    }

    vector<int> from_s_dp(n, 0), from_t_dp(n, 0);

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    from_s_dp[s] = 1, from_t_dp[t] = 1;

    reverse(nodes.begin(), nodes.end());

    for (auto &u: nodes) {
        for (auto &[v, w]: path[u]) {
            if (dis[u] - dis[v] == w) {
                add(from_s_dp[v], from_s_dp[u]);
            }
        }
    }

    if (dis[s] == l) return cout << from_s_dp[t], 0;

    reverse(nodes.begin(), nodes.end());

    for (auto &u: nodes) {
        for (auto &[v, w]: path[u]) {
            if (dis[v] - dis[u] == w) {
                add(from_t_dp[v], from_t_dp[u]);
            }
        }
    }

    int ans = 0;

    for (int u = 0; u < n; u ++) {
        if (from_s_dp[u]) {
            for (auto &[v, w]: path[u]) {
                if (dis[s] - dis[u] + w + dis[v] == l && u != t) {
                    add(ans, 1ll * from_s_dp[u] * from_t_dp[v] % mod);
                }
            }
        }
    }

    cout << ans;

    return 0;
}