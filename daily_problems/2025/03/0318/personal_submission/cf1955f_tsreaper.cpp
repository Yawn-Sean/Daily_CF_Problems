#include <bits/stdc++.h>
#define MAXN 200
#define INF ((int) 1e9)
using namespace std;

int f[MAXN + 5][MAXN + 5][MAXN + 5];

int calc(int a, int b, int c) {
    int t = (1 * (a & 1)) ^ (2 * (b & 1)) ^ (3 * (c & 1));
    return t == 0 ? 1 : 0;
}

int main() {
    for (int i = 0; i <= MAXN; i++) for (int j = 0; j <= MAXN; j++) for (int k = 0; k <= MAXN; k++) f[i][j][k] = -INF;
    f[0][0][0] = 0;
    for (int i = 0; i <= MAXN; i++) for (int j = 0; j <= MAXN; j++) for (int k = 0; k <= MAXN; k++) {
        if (i < MAXN) f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k] + calc(i + 1, j, k));
        if (j < MAXN) f[i][j + 1][k] = max(f[i][j + 1][k], f[i][j][k] + calc(i, j + 1, k));
        if (k < MAXN) f[i][j][k + 1] = max(f[i][j][k + 1], f[i][j][k] + calc(i, j, k + 1));
    }

    int tcase; scanf("%d", &tcase);
    while (tcase--) {
        int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", f[a][b][c] + d / 2);
    }
    return 0;
}
