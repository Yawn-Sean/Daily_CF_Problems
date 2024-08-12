#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
using PIII = std::pair<int, PII>;
const int inf = 1e9 + 7, P = 1e9 + 7;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 1, a, b; i < n; ++ i) {
        std::cin >> a >> b;
        -- a, -- b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    std::vector<int> sz(n, 1);
    std::vector<bool> color(n);
    int con = 0;

    auto dfs = [&](auto&& self, int u, int fa) -> void {
        con += color[u];
        for (int v : g[u]) {
            if (v == fa) continue;
            color[v] = color[u] ^ 1;
            self(self, v, u);
            sz[u] += sz[v];
        }
    };

    dfs(dfs, 0, -1);

    i64 res = 1LL * con * (n - con);
    for (int x : sz)
        res += 1LL * (n - x) * x;
    std::cout << res / 2;
}


int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}