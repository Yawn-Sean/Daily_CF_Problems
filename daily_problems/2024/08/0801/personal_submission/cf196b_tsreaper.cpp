#include <bits/stdc++.h>
#define MAXN 1500
#define MAXM 1500
using namespace std;
typedef pair<int, int> pii;

int n, m;
char MAP[MAXN + 10][MAXM + 10];

bool vis[MAXN + 10][MAXM + 10];
pii bias[MAXN + 10][MAXM + 10];
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

bool bfs(int SI, int SJ) {
    queue<pii> q; q.push({SI, SJ});
    vis[SI][SJ] = true; bias[SI][SJ] = {0, 0};
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        int i = p.first, j = p.second;
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            int bi = bias[i][j].first, bj = bias[i][j].second;
            if (ii < 0) ii += n, bi--;
            if (ii >= n) ii -= n, bi++;
            if (jj < 0) jj += m, bj--;
            if (jj >= m) jj -= m, bj++;
            if (MAP[ii][jj] == '#') continue;
            if (vis[ii][jj]) {
                if (bias[ii][jj] != pii(bi, bj)) return true;
                continue;
            }
            q.push({ii, jj});
            vis[ii][jj] = true; bias[ii][jj] = {bi, bj};
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", MAP[i]);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (MAP[i][j] == 'S') {
        if (bfs(i, j)) printf("Yes\n");
        else printf("No\n");
        return 0;
    }
    return 0;
}
