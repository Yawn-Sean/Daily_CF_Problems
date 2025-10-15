#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, q;

long long f[MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5], h[MAXN + 5][MAXN + 5];

void solve() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        int x; scanf("%d", &x);
        f[i][j] = f[i][j - 1] + x;
        g[i][j] = g[i][j - 1] + 1LL * i * x;
        h[i][j] = h[i][j - 1] + 1LL * j * x;
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        f[i][j] += f[i - 1][j];
        g[i][j] += g[i - 1][j];
        h[i][j] += h[i - 1][j];
    }

    while (q--) {
        int i1, j1, i2, j2; scanf("%d%d%d%d", &i1, &j1, &i2, &j2);
        int m = j2 - j1 + 1;
        long long x = g[i2][j2] - g[i1 - 1][j2] - g[i2][j1 - 1] + g[i1 - 1][j1 - 1];
        x *= m;
        long long y = h[i2][j2] - h[i1 - 1][j2] - h[i2][j1 - 1] + h[i1 - 1][j1 - 1];
        long long z = f[i2][j2] - f[i1 - 1][j2] - f[i2][j1 - 1] + f[i1 - 1][j1 - 1];
        z *= 1LL * i1 * m + j1 - 1;
        printf("%lld ", x + y - z);
    }
    printf("\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
