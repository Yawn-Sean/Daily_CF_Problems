#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n, m;
char MAP[MAXN + 5][MAXN + 5];

bool vis[MAXN + 5][MAXN + 5];
vector<array<int, 3>> ans;
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

void dfs(int i, int j, bool red) {
    vis[i][j] = true;
    ans.push_back({(int) 'B', i, j});
    for (int k = 0; k < 4; k++) {
        int ii = i + dir[k][0], jj = j + dir[k][1];
        if (ii <= 0 || jj <= 0 || ii > n || jj > m || MAP[ii][jj] == '#' || vis[ii][jj]) continue;
        dfs(ii, jj, true);
    }
    if (red) {
        ans.push_back({(int) 'D', i, j});
        ans.push_back({(int) 'R', i, j});
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        if (MAP[i][j] == '.' && !vis[i][j]) dfs(i, j, false);
    printf("%d\n", ans.size());
    for (auto &arr : ans) printf("%c %d %d\n", arr[0], arr[1], arr[2]);
    return 0;
}
