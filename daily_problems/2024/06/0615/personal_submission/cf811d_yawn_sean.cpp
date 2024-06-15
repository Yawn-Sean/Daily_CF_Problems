#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

pair<int, int> op(char c) {
    cout << c << '\n';
    cout << flush;
    int x, y;
    cin >> x >> y;
    x --, y --;
    return {x, y};
}

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
    
    vector<vector<int>> vis(n, vector<int>(m));
    vector<vector<pair<int, int>>> pre(n, vector<pair<int, int>>(m));

    int endx = -1, endy = -1;

    vector<int> dirs_u = {1, 0, -1, 0};
    vector<int> dirs_v = {0, 1, 0, -1};

    auto dfs = [&] (auto&& dfs, int u, int v) -> int {
        if (grid[u][v] == 'F')
            endx = u, endy = v;
        for (int i = 0; i < 4; i ++) {
            int du = dirs_u[i], dv = dirs_v[i];
            if ((u + du >= 0) && (u + du < n) && (v + dv >= 0) && (v + dv < m) &&
                (grid[u+du][v+dv] != '*') && !vis[u+du][v+dv]) {
                    pre[u+du][v+dv] = {u, v};
                    vis[u+du][v+dv] = 1;
                    dfs(dfs, u+du, v+dv);
                }
        }
        return 0;
    };

    vis[0][0] = 1;
    dfs(dfs, 0, 0);
    vector<pair<int, int>> path;
    int x = endx, y = endy;

    while (x || y) {
        path.push_back({x, y});
        int nx = pre[x][y].first, ny = pre[x][y].second;
        x = nx, y = ny;
    }

    path.push_back({0, 0});
    reverse(path.begin(), path.end());

    string ud = "UD", lr = "LR";
    bool f_ud = false, f_lr = false;
    int k = path.size();

    for (int i = 1; i < k; i ++) {
        int dx = path[i].first - path[i-1].first, dy = path[i].second - path[i-1].second;
        if (dx == 0) {
            if (!f_lr) {
                f_lr = true;
                int y = op('L').second;
                if (y == path[i].second) lr = "RL";
                else op('R');
            }
            else op(lr[dy > 0]);
        }
        else {
            if (!f_ud) {
                f_ud = true;
                int x = op('U').first;
                if (x == path[i].first) ud = "DU";
                else op('D');
            }
            else op(ud[dx > 0]);
        }
    }

    return 0;
}