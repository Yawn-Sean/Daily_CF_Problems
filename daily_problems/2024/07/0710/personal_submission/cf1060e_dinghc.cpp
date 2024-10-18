#include <bits/stdc++.h>

using namespace std;
using li = long long;

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0, u, v; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    li ans = 0LL;
    vector<int> sz(n, 0);
    int colors[2]{};
    function<int(int,int,int)> dfs = [&] (int u, int p, int c) -> int {
        sz[u] = 1;
        colors[c]++;
        for (auto& v : g[u]) {
            if (v != p) {
                sz[u] += dfs(v, u, c ^ 1);
            }
        }
        if (p != -1) ans += 1LL * sz[u] * (n - sz[u]);
        return sz[u];
    };
    dfs(0, -1, 0);
    ans = (ans + 1LL * colors[0] * colors[1]) / 2;
    printf("%lld\n", ans);
    return 0;
}

