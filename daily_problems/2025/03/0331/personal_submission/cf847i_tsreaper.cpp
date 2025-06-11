#include <bits/stdc++.h>
#define MAXN 250
using namespace std;

int n, m, X, Y, ans;
char MAP[MAXN + 5][MAXN + 5];

int val[MAXN + 5][MAXN + 5];
bool vis[MAXN + 5][MAXN + 5];
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

void bfs(int SI, int SJ) {
    queue<array<int, 3>> q;
    q.push({SI, SJ, (MAP[SI][SJ] - 'A' + 1) * X}); vis[SI][SJ] = true;

    vector<array<int, 2>> vec;
    while (!q.empty()) {
        auto arr = q.front(); q.pop();
        int i = arr[0], j = arr[1], v = arr[2];
        val[i][j] += v;
        vec.push_back({i, j});
        if (v / 2 == 0) continue;
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii <= 0 || jj <= 0 || ii > n || jj > m || vis[ii][jj] || MAP[ii][jj] == '*') continue;
            q.push({ii, jj, v / 2}); vis[ii][jj] = true;
        }
    }

    for (auto &arr : vec) vis[arr[0]][arr[1]] = false;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &X, &Y);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        if (MAP[i][j] >= 'A' && MAP[i][j] <= 'Z') bfs(i, j);
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (val[i][j] > Y) ans++;
    printf("%d\n", ans);
    return 0;
}
