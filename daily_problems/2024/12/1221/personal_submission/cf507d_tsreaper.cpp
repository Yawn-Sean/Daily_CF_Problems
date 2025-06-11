#include <bits/stdc++.h>
#define MAXN 1000
#define MAXK 100
using namespace std;

int n, K, MOD;

long long f[MAXN + 5][MAXK + 1];
int P[MAXN + 5];

long long dp(int pos, int rem) {
    if (rem < K && rem * P[pos] % K == 0) return 1;
    if (pos == 0) return 0;
    long long &ret = f[pos][rem];
    if (ret >= 0) return ret;
    ret = 0;

    for (int i = (pos == n ? 1 : 0); i <= 9; i++) {
        if (rem == K) {
            ret = (ret + dp(pos - 1, K)) % MOD;
            if (i > 0) ret = (ret + dp(pos - 1, i % K)) % MOD;
        } else {
            ret = (ret + dp(pos - 1, (rem * 10 + i) % K)) % MOD;
        }
    }
    return ret;
}

int main() {
    scanf("%d%d%d", &n, &K, &MOD);
    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 10 % K;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= K; j++) f[i][j] = -1;
    printf("%lld\n", dp(n, K));
    return 0;
}
