#include <bits/stdc++.h>
#define MAXX 100
#define MAXY 100
#define MAXC 10
using namespace std;

int n, q, C;

int f[MAXC + 1][MAXX + 5][MAXY + 5];

int main() {
    scanf("%d%d%d", &n, &q, &C); C++;
    for (int i = 1; i <= n; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        f[z][x][y]++;
    }

    for (int c = 0; c < C; c++) {
        for (int i = 1; i <= MAXX; i++) for (int j = 1; j <= MAXY; j++) f[c][i][j] += f[c][i][j - 1];
        for (int i = 1; i <= MAXX; i++) for (int j = 1; j <= MAXY; j++) f[c][i][j] += f[c][i - 1][j];
    }

    while (q--) {
        int t, xa, ya, xb, yb; scanf("%d%d%d%d%d", &t, &xa, &ya, &xb, &yb);
        int ans = 0;
        for (int c = 0; c < C; c++) {
            int now = (c + t) % C;
            int cnt = f[c][xb][yb] - f[c][xa - 1][yb] - f[c][xb][ya - 1] + f[c][xa - 1][ya - 1];
            ans += cnt * now;
        }
        printf("%d\n", ans);
    }
    return 0;
}
