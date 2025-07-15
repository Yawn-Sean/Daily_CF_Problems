#include<bits/stdc++.h>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    vector<pair<int, int>> dirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
    };

    int target = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] != '.') target ++;
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<pair<int, int>> ans;

    for (int i = 0; i < m; i ++) {
        {
            int x = 0, y = i, dir = 1;
            while (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] != '.') {
                    vis[x][y] = 1;
                    dir ^= (grid[x][y] == '\\' ? 1 : 3);
                }
                auto [dx, dy] = dirs[dir];
                x += dx, y += dy;
            }

            int c = 0;
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < m; j ++) {
                    c += vis[i][j];
                    vis[i][j] = 0;
                }
            }
            if (c == target) ans.emplace_back(1, i);
        }
        {
            int x = n - 1, y = i, dir = 3;
            while (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] != '.') {
                    vis[x][y] = 1;
                    dir ^= (grid[x][y] == '\\' ? 1 : 3);
                }
                auto [dx, dy] = dirs[dir];
                x += dx, y += dy;
            }

            int c = 0;
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < m; j ++) {
                    c += vis[i][j];
                    vis[i][j] = 0;
                }
            }
            if (c == target) ans.emplace_back(3, i);
        }
    }

    for (int i = 0; i < n; i ++) {
        {
            int x = i, y = 0, dir = 0;
            while (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] != '.') {
                    vis[x][y] = 1;
                    dir ^= (grid[x][y] == '\\' ? 1 : 3);
                }
                auto [dx, dy] = dirs[dir];
                x += dx, y += dy;
            }

            int c = 0;
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < m; j ++) {
                    c += vis[i][j];
                    vis[i][j] = 0;
                }
            }
            if (c == target) ans.emplace_back(0, i);
        }
        {
            int x = i, y = m - 1, dir = 2;
            while (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] != '.') {
                    vis[x][y] = 1;
                    dir ^= (grid[x][y] == '\\' ? 1 : 3);
                }
                auto [dx, dy] = dirs[dir];
                x += dx, y += dy;
            }

            int c = 0;
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < m; j ++) {
                    c += vis[i][j];
                    vis[i][j] = 0;
                }
            }
            if (c == target) ans.emplace_back(2, i);
        }
    }

    cout << ans.size() << '\n';
    for (auto &[x, y]: ans) {
        if (x == 0) cout << 'W' << y + 1 << ' ';
        else if (x == 1) cout << 'N' << y + 1 << ' ';
        else if (x == 2) cout << 'E' << y + 1 << ' ';
        else cout << 'S' << y + 1 << ' ';
    }

    return 0;
}
