#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;
typedef long double ldb;

int n, m;

int nR, nC;
bool R[MAXN + 5], C[MAXN + 5];
ldb f[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);

    nR = nC = n;
    while (m--) {
        int r, c; scanf("%d%d", &r, &c);
        if (!R[r]) R[r] = true, nR--;
        if (!C[c]) C[c] = true, nC--;
    }

    for (int i = 0; i <= nR; i++) for (int j = 0; j <= nC; j++) if (i + j > 0) {
        int t = i * n + j * n - i * j;
        ldb v = 1.0 * n * n / t;
        if (i > 0) f[i][j] += (f[i - 1][j] + v) * (t - j * n) / t;
        if (j > 0) f[i][j] += (f[i][j - 1] + v) * (t - i * n) / t;
        if (i > 0 && j > 0) f[i][j] += (f[i - 1][j - 1] + v) * (i * j) / t;
    }
    printf("%.12Lf\n", f[nR][nC]);
    return 0;
}
