#include <bits/stdc++.h>
#define MAXN 5000
#define MAXA 5000
#define INF ((long long) 1e18)
using namespace std;

int n, A[MAXN + 5], B[MAXN + 5], C[MAXN + 5];
long long ans;

long long f[2][MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &C[i]);

    for (int j = 0; j <= MAXA; j++) f[n & 1 ^ 1][j] = -INF;
    f[n & 1 ^ 1][0] = 0;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j <= MAXA; j++) f[i & 1][j] = f[i & 1 ^ 1][j] + min(A[i], j);
        for (int j = 0; j <= MAXA; j++) {
            int jj = min(j + B[i], MAXA);
            f[i & 1][jj] = max(f[i & 1][jj], f[i & 1 ^ 1][j] + min(A[i], jj) - C[i]);
        }
    }

    ans = -INF;
    for (int j = 0; j <= MAXA; j++) ans = max(ans, f[1][j]);
    printf("%lld\n", ans);
    return 0;
}
