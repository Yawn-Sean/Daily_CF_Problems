#include <bits/stdc++.h>
#define MAXN 40
using namespace std;

int n, m, q;
char MAP[MAXN + 5][MAXN + 5];

int f[MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5][MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[i][j] = f[i][j - 1] + MAP[i][j] - '0';
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[i][j] += f[i - 1][j];

    for (int u = 1; u <= n; u++) for (int l = 1; l <= m; l++) {
        for (int d = u; d <= n; d++) for (int r = l; r <= m; r++) {
            g[u][l][d][r] = g[u][l][d][r - 1];
            int v = f[d][r] - f[u - 1][r] - f[d][l - 1] + f[u - 1][l - 1];
            if (v == 0) g[u][l][d][r]++;
        }
        for (int d = u; d <= n; d++) for (int r = l; r <= m; r++) g[u][l][d][r] += g[u][l][d - 1][r];
    }

    for (int u = n; u > 0; u--) for (int l = m; l > 0; l--) for (int d = u; d <= n; d++) for (int r = l; r <= m; r++)
        g[u][l][d][r] += g[u][l + 1][d][r];
    for (int u = n; u > 0; u--) for (int l = m; l > 0; l--) for (int d = u; d <= n; d++) for (int r = l; r <= m; r++)
        g[u][l][d][r] += g[u + 1][l][d][r];

    while (q--) {
        int u, l, d, r; scanf("%d%d%d%d", &u, &l, &d, &r);
        printf("%d\n", g[u][l][d][r]);
    }
    return 0;
}
