#include <bits/stdc++.h>
#define MAXN ((int) 1e3)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K;
char s[MAXN + 10];
long long ans;

int f[MAXN + 10];
long long C[MAXN + 10][MAXN + 10];

int main() {
    for (int i = 2; i <= MAXN; i++) f[i] = f[__builtin_popcount(i)] + 1;
    for (int i = 0; i <= MAXN; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }

    scanf("%s%d", s + 1, &K); n = strlen(s + 1);
    if (K == 0) { printf("1\n"); return 0; }
    for (int g = 1; g <= MAXN; g++) if (f[g] == K - 1) {
        int rem = g;
        for (int i = 1; i <= n; i++) if (s[i] == '1') {
            if (rem >= 0) ans = (ans + C[n - i][rem]) % MOD;
            rem--;
        }
        if (rem == 0) ans = (ans + 1) % MOD;
    }
    if (K == 1) ans = (ans - 1 + MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}
