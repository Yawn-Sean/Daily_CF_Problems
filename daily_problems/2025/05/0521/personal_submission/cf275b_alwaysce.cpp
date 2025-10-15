#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int inf = 1e9 + 7;
int dist[51][51][4][2];

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            char c = s[j];
            if (c == 'W') { grid[i][j] = 0; }
            else { grid[i][j] = 1; }
        }
    }
    
    auto reset = [&]() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 0; l < 2; l++) {
                        dist[i][j][k][l] = inf;
                    }
                }
            }
        }
    };


    function<void(int, int)> bfs = [&](int i, int j) {
        reset();

        // [turned, i, j, direction]
        deque<array<int, 4>> dq;
        // !turned总是被优先消费
        // turned的放在后面
        for (int k = 0; k < 4; k++) {
            dq.push_back({i, j, k, 0});
            dist[i][j][k][0] = 0;
        }

        while (!dq.empty()) {
            auto [x, y, d, turn] = dq.front();
            dq.pop_front();
            
            int curd = dist[x][y][d][turn];

            for (int nd = 0; nd < 4; nd++) {
                int nx = x + di[nd];
                int ny = y + dj[nd];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (grid[nx][ny] == 0) {
                    continue;
                }

                int cost = (nd == d) ? 0 : 1;
                if (turn && cost) {
                    continue;
                }

                int newTurn = turn || (cost == 1);
                int nxtd = curd + cost;
                if (nxtd < dist[nx][ny][nd][newTurn]) {
                    dist[nx][ny][nd][newTurn] = nxtd;
                    if (cost == 0) {
                        dq.push_front({nx, ny, nd, newTurn});
                    } else {
                        dq.push_back({nx, ny, nd, newTurn});
                    }
                }
            }
        }

    };

    auto check = [&]() {
        bool res = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    bool ok = false;
                    for (int k = 0; k < 4; k++) {
                        ok |= (dist[i][j][k][0] < inf);
                        ok |= (dist[i][j][k][1] < inf);
                    }
                    res &= ok;
                    if (!res) { return false; }
                }
            }
        }
        return true;
    };

    bool ans = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                bfs(i, j);
                ans &= check();
                if (!ans) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    return 0;
}
