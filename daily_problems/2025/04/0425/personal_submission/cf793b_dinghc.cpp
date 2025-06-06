#include <bits/stdc++.h>
 
using namespace std;
constexpr int INF = 1e6;
constexpr int N = 1000;
char grid[N][N + 1];
vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    int s_x, s_y;
    int t_x, t_y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                s_x = i;
                s_y = j;
            } else if (grid[i][j] == 'T') {
                t_x = i;
                t_y = j;
            }
        }
    }
    vector<vector<array<int, 4>>> cost(n, vector<array<int, 4>>(m, array<int, 4>{INF, INF, INF, INF}));
    cost[s_x][s_y] = {0, 0, 0, 0};
    deque<array<int, 3>> q;
    q.push_back(array<int, 3>{s_x, s_y, 0});
    q.push_back(array<int, 3>{s_x, s_y, 1});
    q.push_back(array<int, 3>{s_x, s_y, 2});
    q.push_back(array<int, 3>{s_x, s_y, 3});
    while (!q.empty()) {
        auto p = q.front(); q.pop_front();
        int x = p[0], y = p[1], d = p[2];
        for (int di = 0; di < 4; di++) {
            auto& [dx, dy] = dirs[di];
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (grid[nx][ny] != '*') {
                    if (di == d && cost[x][y][d] < cost[nx][ny][di]) {
                        cost[nx][ny][di] = cost[x][y][d];
                        q.push_front(array<int, 3>{nx, ny, di});
                    } else if (di != d && cost[x][y][d] + 1 < cost[nx][ny][di]) {
                        cost[nx][ny][di] = cost[x][y][d] + 1;
                        q.push_back(array<int, 3>{nx, ny, di});
                    }
                }
            }
        }
    }
    for (int di = 0; di < 4; di++) {
        if (cost[t_x][t_y][di] < 3) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

