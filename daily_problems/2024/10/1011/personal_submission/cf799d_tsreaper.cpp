#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXX ((int) 1e5)
using namespace std;

int X, Y, H, W, n, A[MAXN + 10];
long long f[2][MAXX + 10];

int main() {
    scanf("%d%d%d%d%d", &X, &Y, &H, &W, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1, greater<int>());

    if ((H >= X && W >= Y) || (H >= Y && W >= X)) { printf("0\n"); return 0; }
    long long lim = max(X, Y);
    f[0][H] = W;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= lim; j++) f[i & 1][j] = 0;
        for (int j = H; j <= lim; j++) {
            f[i & 1][j] = max(f[i & 1][j], min(lim, f[i & 1 ^ 1][j] * A[i]));
            int jj = min(lim, 1LL * j * A[i]);
            f[i & 1][jj] = max(f[i & 1][jj], f[i & 1 ^ 1][j]);
        }
        for (int j = 0; j <= lim; j++) {
            if (j >= X && f[i & 1][j] >= Y) { printf("%d\n", i); return 0; }
            if (j >= Y && f[i & 1][j] >= X) { printf("%d\n", i); return 0; }
        }
    }
    printf("-1\n");
    return 0;
}
