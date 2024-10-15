#include <bits/stdc++.h>
 
using i64 = long long;
 
const int N = 2E5 + 10;
 
std::vector<int> g[N];
int dep[N], fa[N][20];
 
void dfs(int x, int father) {
    dep[x] = dep[father] + 1;
    fa[x][0] = father;
    for (int i = 1; i < 19; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (int y : g[x]) {
        if (y != father) {
            dfs(y, x);
        }
    }
}
 
int lca(int x, int y) {
    if (dep[x] < dep[y]) {
        std::swap(x, y);
    }
    // jump to the same level
    for (int i = 19; ~i; i--) {
        if (dep[fa[x][i]] >= dep[y]) {
            x = fa[x][i];
        }
    }
    if (x == y) {
        return x;
    }
    // jump to the next level of the LCA
    for (int i = 19; ~i; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}
 
int dis(int x, int y) {
    int t = lca(x, y);
    return dep[x] + dep[y] - 2 * dep[t];
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int x;
        std::cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs(1, 0);
    while (m--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int v1 = dis(a, b), v2 = dis(b, c), v3 = dis(a, c);
        // std::cout << v1 << ' ' << v2 << ' ' << v3 << '\n';
        int x = ((v1 + v2 + v3) - v2 * 2) / 2 + 1, y = ((v1 + v2 + v3) - v3 * 2) / 2 + 1, z = ((v1 + v2 + v3) - v1 * 2) / 2 + 1;
        std::cout << std::max({x, y, z}) << '\n';
    }
 
    return 0;
}
