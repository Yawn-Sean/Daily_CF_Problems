#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXK 10
#define MOD 998244353
using namespace std;

int n, K;
long long ans;

long long f[MAXN + 5][MAXK + 1], g[MAXN + 5][MAXK + 1];

int main() {
    scanf("%d%d", &n, &K);
    
    for (int i = 1; i <= n; i++) {
        f[i][1] = 1;
        for (int j = 2; j <= K && j <= i; j++)
            f[i][j] = (g[i - 1][j - 1] - f[i - 2][j - 1] + MOD) % MOD;
        if (i >= K) f[i][K] = (f[i][K] + g[i - 1][K] - f[i - 2][K] + MOD) % MOD;
        for (int j = 1; j <= K; j++) g[i][j] = (g[i - 1][j] + f[i][j]) % MOD;
    }

    for (int i = 1; i <= n - 1; i++) ans = (ans + f[i][K - 1] + f[i][K]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
