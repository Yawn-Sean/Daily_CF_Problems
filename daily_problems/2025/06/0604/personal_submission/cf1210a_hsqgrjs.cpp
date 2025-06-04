#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> e(n + 1, std::vector<int>());
    for(int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    std::vector<std::pair<int, int>> t;
    for(int i = 1; i <= 6; i++) {
        for(int j = i; j <= 6; j++) {
            t.push_back({i, j});
        }
    }
    std::map<std::pair<int, int>, int> ss;
    int cnt = 0;
    for(auto [l, r] : t) {
        ss[{l, r}] = ss[{r, l}] = cnt++;
    }
    int val[10] = {0};
    int ans = 0;
    std::function<void(int)> dfs = [&](int x)-> void {
        if(x > n) {
            bool vv[30] = {0};
            for(int u = 1; u <= n; u++) {
                for(auto v : e[u]) {
                    vv[ss[{val[u], val[v]}]] = 1;
                }
            }
            int a1 = 0;
            for(int i = 1; i <= 21; i++) {
                a1 += vv[i];
            }
            if(a1 > ans) ans = a1;
            return ;
        }
        for(int i = 1; i <= 6; i++) {
            val[x] = i;
            dfs(x + 1);
        }
    };

    dfs(1);

    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;  
    // std::cin >> t;
    while (t--)
        solve();
    return 0;
}
