#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, q, p;
    cin >> n >> m >> q >> p;

    vector<vector<int>> cnt(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') { vis[i][j] = -1;}
        }
    }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] >= 'A' && grid[i][j] <= 'Z') {
                queue<pair<int,int>> que;
                que.push({i, j});
                vis[i][j] = (grid[i][j] - 'A' + 1) * q;
                vector<pair<int,int>> cur;

                while (!que.empty()) {
                    auto [x, y] = que.front();
                    que.pop();
                    cur.emplace_back(x, y);
                    cnt[x][y] += vis[x][y];
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] != 0) continue;
                        vis[nx][ny] = vis[x][y] / 2;
                        if (vis[nx][ny] > 0) {
                            que.push({nx, ny});
                        }
                    }
                }

                for (auto& [x, y]: cur) {
                    vis[x][y] = 0;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout << cnt[i][j] << ' ';
            if (cnt[i][j] > p) {
                ans++;
            }
        }
        // cout << '\n';
    }
    cout << ans << '\n';
    return 0;
}
