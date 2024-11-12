#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> sizes(n + 1, 0);
    function<int(int,int)> dfs = [&] (int u, int p) -> int {
        int res = 1;
        for (auto& w : g[u]) {
            if (w != p) res += dfs(w, u);
        }
        return sizes[u] = res;
    };
    dfs(x, 0);
    int64 ans = sizes[y];
    dfs(y, 0);
    ans *= sizes[x];
    printf("%lld\n", 1LL * (n - 1) * n - ans);
    return 0;
}

