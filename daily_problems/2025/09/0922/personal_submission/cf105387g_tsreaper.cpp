#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, A[3];
long long ans;

long long f[MAXN + 5][3], g[MAXN + 5][3];

int main() {
    scanf("%d", &n);
    for (int j = 0; j < 3; j++) scanf("%d", &A[j]);

    for (int j = 0; j < 3; j++) f[1][j] = g[1][j] = 1;
    for (int i = 2; i <= n; i++) for (int j = 0; j < 3; j++) {
        for (int jj = 0; jj < 3; jj++) if (j != jj) f[i][j] = (f[i][j] + g[i - 1][jj] - g[max(0, i - A[j] - 1)][jj] + MOD) % MOD;
        if (i <= A[j]) f[i][j] = (f[i][j] + 1) % MOD;
        g[i][j] = (g[i - 1][j] + f[i][j]) % MOD;
    }
    
    for (int j = 0; j < 3; j++) ans = (ans + f[n][j]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
