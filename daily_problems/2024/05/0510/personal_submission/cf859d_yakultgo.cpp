#include <bits/stdc++.h>
#define MAXN 6
using namespace std;
typedef long double ldb;

int n, A[1 << MAXN][1 << MAXN];
ldb ans;

ldb f[MAXN + 1][1 << MAXN], g[MAXN + 1][1 << MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i++) for (int j = 0; j < (1 << n); j++) scanf("%d", &A[i][j]);

    for (int i = 0; i < (1 << n); i++) g[0][i] = 1;
    for (int p = 1; p <= n; p++) for (int i = 0; i < (1 << n); i++) {
        int x = i >> (p - 1), y = x ^ 1;
        int l = (1 << (p - 1)) * y, r = l + (1 << (p - 1));

        f[p][i] = f[p - 1][i];
        ldb best = 0;
        for (int j = l; j < r; j++) best = max(best, f[p - 1][j]);
        f[p][i] += best;

        for (int j = l; j < r; j++) {
            ldb t = g[p - 1][i] * g[p - 1][j] * A[i][j] / 100;
            f[p][i] += t * (1 << (p - 1));
            g[p][i] += t;
        }
    }

    for (int i = 0; i < (1 << n); i++) ans = max(ans, f[n][i]);
    printf("%.15Lf\n", ans);
    return 0;
}
