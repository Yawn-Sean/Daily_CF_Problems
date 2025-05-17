#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> g(n);
    for (int i = 1, x, y; i < n; i++) {
        scanf("%d%d", &x, &y);
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    int ans = 1;
    vector<int> colors(n);
    auto dfs = [&] (this auto&& dfs, int u, int p) -> void {
        int curr = 1;
        while (colors[u] == curr || p != -1 && colors[p] == curr) curr += 1;
        for (auto& v : g[u]) if (v != p) {
            ans = max(ans, curr);
            colors[v] = curr++;
            dfs(v, u);
            while (colors[u] == curr || p != -1 && colors[p] == curr) curr += 1;
        }
    };
    colors[0] = 1;
    dfs(0, -1);
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) printf("%d ", colors[i]);
    return 0;
}

