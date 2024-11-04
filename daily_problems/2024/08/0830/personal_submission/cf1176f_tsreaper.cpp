#include <bits/stdc++.h>
#define MAGIC 10
#define MAXC 3
#define INF ((long long) 1e18)
using namespace std;

long long f[2][MAGIC], g[MAXC + 1][MAXC + 1][2];

void gao() {
    int m; scanf("%d", &m);
    for (int j = 0; j <= MAXC; j++) for (int c = 0; c <= MAXC; c++) g[j][c][0] = g[j][c][1] = -INF;
    g[0][0][0] = 0;
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        for (int j = MAXC; j > 0; j--) for (int c = x; c <= MAXC; c++) {
            g[j][c][0] = max(g[j][c][0], g[j - 1][c - x][0] + y);
            g[j][c][1] = max({g[j][c][1], g[j - 1][c - x][0] + y * 2, g[j - 1][c - x][1] + y});
        }
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int j = 0; j < MAGIC; j++) f[0][j] = -INF;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        gao();
        for (int j = 0; j < MAGIC; j++) {
            f[i & 1][j] = -INF;
            for (int jj = 0; jj <= MAXC; jj++) {
                long long mx = -INF;
                for (int c = jj; c <= MAXC; c++) {
                    if (j < jj) mx = max(mx, g[jj][c][1]);
                    else mx = max(mx, g[jj][c][0]);
                }
                f[i & 1][j] = max(f[i & 1][j], f[i & 1 ^ 1][(j - jj + MAGIC) % MAGIC] + mx);
            }
        }
    }

    long long ans = -INF;
    for (int j = 0; j < MAGIC; j++) ans = max(ans, f[n & 1][j]);
    printf("%lld\n", ans);
    return 0;
}
