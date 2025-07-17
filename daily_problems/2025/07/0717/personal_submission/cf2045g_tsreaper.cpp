#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m, K;
char MAP[MAXN + 5][MAXN + 5];

long long f[MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5];
int P[10][10];

int dis(int i, int j, int ii, int jj) {
    int x = MAP[i][j] - '0', y = MAP[ii][jj] - '0';
    return P[abs(x - y)][K] * (x >= y ? 1 : -1);
}

int main() {
    for (int i = 0; i < 10; i++) {
        P[i][0] = 1;
        for (int j = 1; j < 10; j++) P[i][j] = P[i][j - 1] * i;
    }

    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    for (int i = 1; i <= n; i++) for (int j = 2; j <= m; j++) f[i][j] = f[i][j - 1] + dis(i, j - 1, i, j);
    for (int i = 2; i <= n; i++) for (int j = 1; j <= m; j++) g[i][j] = g[i - 1][j] + dis(i - 1, j, i, j);

    bool bad = false;
    short dir[4][2] = {0, 0, 0, 1, 1, 1, 1, 0};
    for (int i = 1; i < n; i++) for (int j = 1; j < m; j++) {
        long long t = 0;
        for (int k = 0; k < 4; k++) t += dis(i + dir[k][0], j + dir[k][1], i + dir[(k + 1) % 4][0], j + dir[(k + 1) % 4][1]);
        if (t != 0) bad = true;
    }

    int q; scanf("%d", &q);
    while (q--) {
        int i1, j1, i2, j2; scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
        if (bad) printf("INVALID\n");
        else printf("%lld\n", (f[i1][j2] - f[i1][j1]) + (g[i2][j2] - g[i1][j2]));
    }
    return 0;
}
