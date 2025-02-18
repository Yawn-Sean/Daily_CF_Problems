#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1'000'000'000;
constexpr int N = 1000;
char s[N + 1];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<vector<int>> maze(n, vector<int>(m, 0));
    int x, y;
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            if (s[j] == '*') maze[i][j] = 1;
            if (s[j] == 'X') x = i, y = j;
        }
    }
    if (k & 1) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    const vector<pair<int, int>> dirs {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    const vector<char> letters {'D', 'L', 'R', 'U'};
    vector<vector<int>> cost(n, vector<int>(m, INF));
    set<array<int, 3>> q;
    q.insert(array<int, 3> {0, x, y});
    cost[x][y] = 0;
    while (!q.empty()) {
        auto [wu, ux, uy] = *q.begin(); q.erase(q.begin());
        for (auto& [dx, dy] : dirs) {
            int nx = ux + dx, ny = uy + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maze[nx][ny] == 0 && cost[nx][ny] > wu + 1) {
                auto it = q.find(array<int, 3> {cost[nx][ny], nx, ny});
                if (it != q.end()) q.erase(it);
                cost[nx][ny] = wu + 1;
                q.insert(array<int, 3> {cost[nx][ny], nx, ny});
            }
        }
    }
    string ans(k, ' ');
    for (int i = 1; i <= k; i++) {
        bool flg = false;
        for (int d = 0; d < 4; d++) {
            auto& [dx, dy] = dirs[d];
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maze[nx][ny] == 0 && cost[nx][ny] <= k - i) {
                ans[i - 1] = letters[d];
                x = nx, y = ny;
                flg = true;
                break;
            }
        }
        if (!flg) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    printf("%s\n", ans.c_str());
    return 0;
}

