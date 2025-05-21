#include <bits/stdc++.h>
#define MAXN 50
using namespace std;

int n, m;
char MAP[MAXN + 5][MAXN + 5];

bool vis[MAXN + 5][MAXN + 5];
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

bool check(int SI, int SJ) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) vis[i][j] = false;
    for (int k = 0; k < 4; k++) for (int d = 0; ; d++) {
        int i = SI + dir[k][0] * d, j = SJ + dir[k][1] * d;
        if (i <= 0 || j <= 0 || i > n || j > m || MAP[i][j] == 'W') break;
        vis[i][j] = true;
        for (int kk = 0; kk < 4; kk++) for (int dd = 0; ; dd++) {
            int ii = i + dir[kk][0] * dd, jj = j + dir[kk][1] * dd;
            if (ii <= 0 || jj <= 0 || ii > n || jj > m || MAP[ii][jj] == 'W') break;
            vis[ii][jj] = true;
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] == 'B' && !vis[i][j]) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (MAP[i][j] == 'B') {
        if (!check(i, j)) { printf("NO\n"); return 0; }
    }
    printf("YES\n"); return 0;
}
