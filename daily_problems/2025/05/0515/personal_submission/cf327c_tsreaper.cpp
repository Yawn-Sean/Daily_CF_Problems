#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K;
char s[MAXN + 5];
long long ans;

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    scanf("%s%d", s + 1, &K); n = strlen(s + 1);
    long long x = (power(2, 1LL * n * K) - 1 + MOD) % MOD;
    long long y = (power(2, n) - 1 + MOD) % MOD;
    long long fac = x * power(y, MOD - 2) % MOD;

    for (int i = 1; i <= n; i++) if (s[i] == '0' || s[i] == '5')
        ans = (ans + power(2, i - 1) * fac) % MOD;
    printf("%lld\n", ans);
    return 0;
}
