#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
#define MAXK 5000
#define INF ((long long) 1e18)
using namespace std;

int n, K, A[MAXN + 10];

long long f[2][MAXK + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);

    int m = n % K;
    for (int j = 0; j <= m; j++) f[0][j] = -INF;
    f[0][0] = 0;
    for (int i = 1; i < K; i++) {
        for (int j = 0; j <= m; j++) f[i & 1][j] = -INF;
        for (int j = 0; j <= i && j <= m; j++) {
            int base = (n / K) * i;
            long long det = A[base + j + 1] - A[base + j];
            f[i & 1][j] = f[i & 1 ^ 1][j];
            if (j > 0) f[i & 1][j] = max(f[i & 1][j], f[i & 1 ^ 1][j - 1]);
            f[i & 1][j] += det;
        }
    }

    long long ans = f[K & 1 ^ 1][m];
    if (m > 0) ans = max(ans, f[K & 1 ^ 1][m - 1]);
    printf("%lld\n", A[n] - A[1] - ans);
    return 0;
}
