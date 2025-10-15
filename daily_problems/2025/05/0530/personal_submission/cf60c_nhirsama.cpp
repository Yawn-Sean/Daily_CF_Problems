//  C. Mushroom Strife
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';
using arr3 = std::array<i32, 3>;

void nhir() {
    i32 n, m;
    std::cin >> n >> m;
    std::vector g(n, std::vector<arr3>());
    while (m--) {
        i32 u, v, lcm, gcd;
        std::cin >> u >> v >> gcd >> lcm;
        u--, v--;
        g[u].push_back({v, gcd, lcm});
        g[v].push_back({u, gcd, lcm});
    }
    std::vector<i32> ans(n);
    for (i32 i = 0; i < n; i++) {
        if (ans[i]) continue;
        if (g[i].size() == 0) {
            ans[i] = 1;
            continue;
        }
        i32 gcd = 0;
        for (auto &j: g[i]) gcd = std::gcd(gcd, j[2]);
        for (i32 j = 1; j <= gcd; j++) {
            if (gcd % j) continue;
            auto dfs = [&](this auto &&dfs, i32 u, i32 zz) -> bool {
                for (auto [v, gc, lc]: g[u]) {
                    if (ans[v]) continue;
                    if (zz > lc * gc) continue;
                    ans[v] = lc * gc / zz;
                    if (!dfs(v, ans[v])) {
                        ans[v] = 0;
                        return false;
                    }
                }
                for (auto [v, gc, lc]: g[u]) {
                    if (std::gcd(ans[u], ans[v]) != gc || std::lcm(ans[u], ans[v]) != lc) {
                        ans[v] = 0;
                        return false;
                    }
                }
                return true;
            };
            if (dfs(i, j)) break;
        }
    }
    if (std::ranges::find(ans, 0) == ans.end()) {
        std::cout << "YES\n";
        for (auto i: ans) {
            std::cout << i << ' ';
        }
    } else {
        std::cout << "NO\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    while (T--) nhir();
    return 0;
}
