#include <bits/stdc++.h>
#define MAXN 100
#define MAXA ((int) 1e4)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K, A[MAXN + 5];
long long ans;

long long f[MAXN + 5][MAXA + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);

    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = A[i] + 1; j <= MAXA + 1; j++) ans = (ans + f[K - 1][j]) % MOD;
        for (int k = K - 1; k >= 0; k--) for (int j = MAXA + 1; j >= 0; j--) {
            int jj = min(j + A[i], MAXA + 1);
            f[k + 1][jj] = (f[k + 1][jj] + f[k][j]) % MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
