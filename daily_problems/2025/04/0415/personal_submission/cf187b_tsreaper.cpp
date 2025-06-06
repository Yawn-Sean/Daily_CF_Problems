#include <bits/stdc++.h>
#define MAXN 60
#define INF ((long long) 1e18)
using namespace std;

int n, K, q;

long long f[MAXN + 5][MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &K, &q);
    for (int t = 0; t <= n; t++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[t][i][j] = INF;
    for (int c = 1; c <= K; c++) {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%lld", &g[c][i][j]);
        for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
            g[c][i][j] = min(g[c][i][j], g[c][i][k] + g[c][k][j]);
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[0][i][j] = min(f[0][i][j], g[c][i][j]);
    }

    for (int t = 1; t <= n; t++) for (int s = 1; s <= n; s++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        f[t][s][j] = min(f[t][s][j], f[t - 1][s][i] + f[0][i][j]);
    for (int t = 1; t <= n; t++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        f[t][i][j] = min(f[t][i][j], f[t - 1][i][j]);

    while (q--) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        z = min(z, n);
        printf("%lld\n", f[z][x][y]);
    }
    return 0;
}
