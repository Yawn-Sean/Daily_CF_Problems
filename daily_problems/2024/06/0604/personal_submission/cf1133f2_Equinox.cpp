#include <bits/stdc++.h>
using PII = std::pair<int, int>;
using i64 = long long;
 
const int inf = 1e9;
 
 
void solve() {
    int N, M, D;
    std::cin >> N >> M >> D;
    std::vector<std::vector<int>> g(N);
    std::vector<int> p(N, -1);
    auto find = [&](auto&& self, int x) -> int {
        return p[x] < 0 ? x : p[x] = self(self, p[x]);
    };

    auto merge = [&](int x, int y) -> void {
        int px = find(find, x), py = find(find, y);
        if (px == py) return;
        if (p[px] > p[py]) std::swap(px, py);
        p[px] += p[py], p[py] = px;
    };

    for (int i = 0, u, v; i < M; i ++ ) {
        std::cin >> u >> v, -- v, -- u;
        g[u].push_back(v), g[v].push_back(u);
    }

    std::vector<bool> vis(N);
    vis[0] = true;
    auto dfs1 = [&](auto&& self, int u, int fa) -> void{
        
        vis[u] = true;
        for (int v : g[u]) {
            if (v == fa || vis[v])  continue;
            merge(u, v);
            self(self, v, u);
        }
    };

    std::unordered_set<int> st;
    for (int v : g[0])
        if (!vis[v])
            dfs1(dfs1, v, 0), st.insert(find(find, v));

    if (st.size() > D || g[0].size() < D) {
        std::cout << "NO";
        return;
    }

    std::vector<std::array<int, 2>> ans; ans.reserve(N - 1);
    vis.assign(N, false), vis[0] = true;
    
    auto dfs2 = [&](auto&& self, int u, int fa) -> void {
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v] && v != fa)
                ans.push_back( { u + 1, v + 1 } ), self(self, v, fa);
    };

    for (int v : g[0]) 
        if (st.count(find(find, v))) 
            vis[v] = true, ans.push_back( { 1, v + 1 } ), D --, st.erase(find(find, v));

    for (int v : g[0])
        if (!vis[v] && D)
            vis[v] = true, ans.push_back( { 1, v + 1 } ), D --;


    for (int v : g[0]) 
        if (vis[v]) 
            dfs2(dfs2, v, 0);

    if (ans.size() + 1 == N) {
        std::cout << "YES\n";
        for (auto& [x, y] : ans)
            std::cout << x << ' ' << y << '\n';
    }
    else 
        std::cout << "NO\n";
}
 
 
int main () {
    std::ios::sync_with_stdio(false);   std::cin.tie(0);  std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}