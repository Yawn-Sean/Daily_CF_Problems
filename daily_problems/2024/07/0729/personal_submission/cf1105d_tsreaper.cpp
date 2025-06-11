#include <bits/stdc++.h>
#define MAXN 1000
#define MAXM 1000
#define MAXP 9
using namespace std;
typedef pair<int, int> pii;

int n, m, P, S[MAXP + 5], ans[MAXP + 5];
char MAP[MAXN + 10][MAXM + 10];

vector<pii> vec[MAXP + 5];
int dis[MAXN + 10][MAXM + 10];
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

bool bfs(int col) {
    queue<pii> q;
    for (pii p : vec[col]) q.push(p), dis[p.first][p.second] = 0;
    vec[col].clear();

    vector<pii> history;
    bool changed = false;
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        history.push_back(p);
        int i = p.first, j = p.second;
        if (dis[i][j] == S[col]) { vec[col].push_back(p); continue; }

        bool flag = false;
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii <= 0 || jj <= 0 || ii > n || jj > m || MAP[ii][jj] != '.') continue;
            flag = true;
            q.push({ii, jj}); MAP[ii][jj] = MAP[i][j]; dis[ii][jj] = dis[i][j] + 1;
        }
        if (flag) {
            changed = true;
            vec[col].push_back(p);
        }
    }

    for (pii p : history) dis[p.first][p.second] = -1;
    return changed;
}

int main() {
    scanf("%d%d%d", &n, &m, &P);
    for (int i = 1; i <= P; i++) scanf("%d", &S[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%s", MAP[i] + 1);
        for (int j = 1; j <= m; j++) if (MAP[i][j] >= '0' && MAP[i][j] <= '9') vec[MAP[i][j] - '0'].push_back({i, j});
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dis[i][j] = -1;
    while (true) {
        bool same = true;
        for (int i = 1; i <= P; i++) if (bfs(i)) same = false;
        if (same) break;
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] >= '0' && MAP[i][j] <= '9') ans[MAP[i][j] - '0']++;
    for (int i = 1; i <= P; i++) printf("%d%c", ans[i], "\n "[i < P]);
    return 0;
}
