#include <bits/stdc++.h>

void solve() {
    constexpr int mod = 998244353, inf = INT_MAX;
    using ary2 = std::array<int,2>;
    // 找最短路 dis，算出最小天数 day = ceil(dis / k)，dp day 次，复杂度(n * k * day)
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> g(n);
    for (int i = 0,u,v; i < m; ++ i){
        std::cin >> u >> v;
        u -= 1, v -= 1;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto find_min_path = [&](int src, int tar)->int{
        std::vector<int> dist(n, inf);
        auto cmps = [&](ary2 x, ary2 y)->bool {
            return x[1] > y[1];
        };
        std::priority_queue<ary2, std::vector<ary2>, decltype(cmps)> pq(cmps);
        dist[src] = 0;
        pq.push({src, 0});
        while (!pq.empty()){
            auto [u, d] = pq.top();
            pq.pop();
            if (d > dist[u]){
                continue;
            }
            for (auto &v : g[u]){
                if (dist[v] > dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    pq.push({v, dist[v]});
                }
            }
        }
        return dist[tar];
    };

    int dis = find_min_path(0, 1);
    if (dis == inf){
        std::cout << 0 << "\n";
        return;
    }

    int day = (dis+k-1) / k;

    std::vector<std::vector<int>> f(n,std::vector<int>(k+1));
    std::vector<int> f_g(n);
    f_g[0] = 1;

    while (day--){
        for (int i = 0; i < n; ++ i){
            f[i][0] = f_g[i];
        }
        for (int j = 0; j < k; ++ j){
            for (int u = 0; u < n; ++ u){
                for (auto &v : g[u]){
                    f[v][j+1] = (f[v][j+1] + f[u][j]) % mod;
                }
            }
        }
        for (int i = 0; i < n; ++ i){
            f_g[i] = 0;
            for (int j = 1; j <= k; ++ j){
                f_g[i] = (f_g[i] + f[i][j]) % mod;
            }
        }
    }

    std::cout << f_g[1] << "\n";
}
