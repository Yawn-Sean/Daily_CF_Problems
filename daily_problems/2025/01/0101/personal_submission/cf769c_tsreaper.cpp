#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n, m, K;
char MAP[MAXN + 5][MAXN + 5];
string ans;

int dis[MAXN + 5][MAXN + 5];
short dir[4][2] = {1, 0, 0, -1, 0, 1, -1, 0};
string chr = "DLRU";

void bfs(int SI, int SJ) {
    queue<pii> q;
    q.push({SI, SJ}); dis[SI][SJ] = 0;
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        int i = p.first, j = p.second;
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii <= 0 || jj <= 0 || ii > n || jj > m || MAP[ii][jj] == '*' || dis[ii][jj] >= 0) continue;
            q.push({ii, jj}); dis[ii][jj] = dis[i][j] + 1;
        }
    }
}

bool solve(int SI, int SJ) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dis[i][j] = -1;
    bfs(SI, SJ);

    int i = SI, j = SJ;
    while (true) {
        K--;
        bool ok = false;
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii <= 0 || jj <= 0 || ii > n || jj > m || MAP[ii][jj] == '*' || dis[ii][jj] > K) continue;
            ans.push_back(chr[k]);
            i = ii; j = jj;
            ok = true;
            break;
        }
        if (ok) {
            if (dis[i][j] == K) break;
        } else {
            return false;
        }
    }

    while (K--) {
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii <= 0 || jj <= 0 || ii > n || jj > m || MAP[ii][jj] == '*' || dis[ii][jj] + 1 != dis[i][j]) continue;
            ans.push_back(chr[k]);
            i = ii; j = jj;
            break;
        }
    }
    return true;
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    if (K & 1) { printf("IMPOSSIBLE\n"); return 0; }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] == 'X') {
        if (solve(i, j)) printf("%s\n", ans.c_str());
        else printf("IMPOSSIBLE\n");
        return 0;
    }
    return 0;
}
