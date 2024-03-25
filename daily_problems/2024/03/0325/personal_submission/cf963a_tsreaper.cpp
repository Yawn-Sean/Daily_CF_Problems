#include <bits/stdc++.h>
#define MAXK ((int) 1e5)
#define MOD ((int) 1e9 + 9)
using namespace std;

int n, A, B, K;
char s[MAXK + 10];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

long long inv(long long x) {
    return power(x, MOD - 2);
}

int sgn(char c) {
    return c == '+' ? 1 : -1;
}

int main() {
    scanf("%d%d%d%d%s", &n, &A, &B, &K, s);
    long long a1 = 0;
    for (int i = 0; i < K; i++) a1 = (a1 + sgn(s[i]) * power(A, n - i) % MOD * power(B, i) % MOD + MOD) % MOD;
    long long q = power(B, K) * power(inv(A), K) % MOD;
    long long ans;
    if (q == 1) ans = a1 * ((n + 1) / K) % MOD;
    else ans = a1 * (1 - power(q, (n + 1) / K) + MOD) % MOD * inv(1 - q + MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}
