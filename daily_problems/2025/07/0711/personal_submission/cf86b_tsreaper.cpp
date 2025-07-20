#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n, m, ans[MAXN + 5][MAXN + 5];
char MAP[MAXN + 5][MAXN + 5];

short dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

bool single(int i, int j) {
    for (int k = 0; k < 4; k++) {
        int ii = i + dir[k][0], jj = j + dir[k][1];
        if (ii > 0 && jj > 0 && ii <= n && jj <= m && MAP[ii][jj] == '.' && ans[ii][jj] == 0) return false;
    }
    return true;
}

void gao(int i, int j, int col) {
    ans[i][j] = col;

    int ii, jj, cnt = 0;
    for (int k = 0; k < 2; k++) {
        ii = i + dir[k][0]; jj = j + dir[k][1];
        if (ii > 0 && jj > 0 && ii <= n && jj <= m && MAP[ii][jj] == '.' && ans[ii][jj] == 0) {
            if (single(ii, jj)) ans[ii][jj] = col, cnt++;
        }
    }
    if (cnt > 0) return;

    for (int k = 0; k < 2; k++) {
        ii = i + dir[k][0]; jj = j + dir[k][1];
        if (ii > 0 && jj > 0 && ii <= n && jj <= m && MAP[ii][jj] == '.' && ans[ii][jj] == 0) break;
    }
    ans[i = ii][j = jj] = col;

    for (int k = 0; k < 4; k++) {
        ii = i + dir[k][0]; jj = j + dir[k][1];
        if (ii > 0 && jj > 0 && ii <= n && jj <= m && MAP[ii][jj] == '.' && ans[ii][jj] == 0) {
            if (single(ii, jj)) ans[ii][jj] = col;
        }
    }
}

void gao2(int i, int j) {
    bool vis[10] = {0};
    queue<pii> q;
    q.push({i, j}); ans[i][j] = -ans[i][j];
    vector<pii> vec;
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        vec.push_back(p);
        i = p.first; j = p.second;
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii <= 0 || jj <= 0 || ii > n || jj > m || MAP[ii][jj] == '#' || ans[ii][jj] == ans[i][j]) continue;
            if (MAP[ii][jj] >= '0' && MAP[ii][jj] <= '9') vis[MAP[ii][jj] - '0'] = true;
            if (ans[ii][jj] == -ans[i][j]) q.push({ii, jj}), ans[ii][jj] = -ans[ii][jj];
        }
    }

    int col = -1;
    for (int i = 0; i < 10; i++) if (!vis[i]) { col = i; break; }
    assert(col >= 0);
    for (pii p : vec) MAP[p.first][p.second] = col + '0';
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    int col = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        if (MAP[i][j] == '.' && !ans[i][j]) {
            if (single(i, j)) { printf("-1\n"); return 0; }
            gao(i, j, ++col);
        }
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] == '.') gao2(i, j);
    for (int i = 1; i <= n; i++) printf("%s\n", MAP[i] + 1);
    return 0;
}
