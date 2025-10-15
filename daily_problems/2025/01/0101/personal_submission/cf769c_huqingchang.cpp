#include <bits/stdc++.h>

using namespace std;


int main() {
    int T = 1;
    for (int ii = 0; ii < T; ++ii) {
        int m, n, k;
        cin >> m >> n >> k;
        cin.ignore(); // 忽略换行符

        vector<string> g;
        for (int i = 0; i < m; ++i) {
            string line;
            getline(cin, line);
            g.push_back(line);
        }

        if (k % 2 == 1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        vector<vector<int>> dis(m, vector<int>(n, numeric_limits<int>::max()));
        int sx = -1, sy = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 'X') {
                    sx = i;
                    sy = j;
                    break;
                }
            }
            if (sx!= -1) {
                break;
            }
        }

        queue<pair<int, int>> dq;
        dq.push({sx, sy});
        dis[sx][sy] = 0;

        auto valid = [&](int a, int b) -> bool {
            return a >= 0 && a < m && b >= 0 && b < n;
        };

        int mx = 0;
        while (!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop();
            vector<pair<int, int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
            for (const auto& dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if (valid(nx, ny) && g[nx][ny]!= '*' && dis[nx][ny] == numeric_limits<int>::max()) {
                    dis[nx][ny] = dis[x][y] + 1;
                    mx = dis[nx][ny];
                    dq.push({nx, ny});
                }
            }
        }

        if (mx == 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        string ans;
        vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
        string word = "DLRU";
        int step = k;
        int x = sx, y = sy;
        while (true) {
            if (step == 0) {
                cout << ans << endl;
                return 0;
            }
            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;
                if (valid(nx, ny) && g[nx][ny]!= '*' && dis[nx][ny] <= step - 1) {
                    ans += word[i];
                    step--;
                    x = nx;
                    y = ny;
                    break;
                }
            }
        }
    }
    return 0;
}
