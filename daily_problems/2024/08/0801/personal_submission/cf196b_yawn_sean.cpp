#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i ++)
        cin >> grid[i];
    
    int sx, sy;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if (grid[i][j] == 'S')
                sx = i, sy = j;

    int inf = 1e9;
    vector<vector<pair<int, int>>> vis(n, vector<pair<int, int>>(m, {inf, inf}));
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool flg = false;

    auto dfs = [&] (auto &&dfs, int x, int y) -> bool {
        if (flg) return true;
        for (auto &[dx, dy]: dirs) {
            int nx = x + dx, ny = y + dy;
            int px = (nx % n + n) % n, py = (ny % m + m) % m;
            if (grid[px][py] == '#') continue;
            if (vis[px][py].first == inf) {
                vis[px][py] = {nx, ny};
                if (dfs(dfs, nx, ny))
                    return true;
            }
            else if (vis[px][py].first != nx || vis[px][py].second != ny) {
                flg = true;
                return true;
            }
        }
        return false;
    };

    vis[sx][sy] = {sx, sy};
    dfs(dfs, sx, sy);

    cout << (flg ? "Yes" : "No");

    return 0;
}