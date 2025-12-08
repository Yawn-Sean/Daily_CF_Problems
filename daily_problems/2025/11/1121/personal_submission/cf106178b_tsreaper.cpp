#include <bits/stdc++.h>
#define MAXK 2000
#define MOD 998244353
using namespace std;

int n, K;
long long f[MAXK + 5][MAXK + 5];

int main() {
    scanf("%d%d", &n, &K);
    n = min(n, K);

    for (int j = 1; j <= K; j++) f[1][j] = j;
    for (int i = 2; i <= n; i++) {
        for (int j = 1, l = 1, r = 1; j <= K; j++) {
            while (l <= K && (i - 1) * l + K < i * j) l++;
            while (r <= K && (i - 1) * r + 1 <= i * j) r++;
            f[i][j] = (f[i - 1][r - 1] - f[i - 1][l - 1] + MOD) % MOD;
        }
        for (int j = 1; j <= K; j++) f[i][j] = (f[i][j] + f[i][j - 1]) % MOD;
    }

    printf("%lld\n", f[n][K]);
    return 0;
}
