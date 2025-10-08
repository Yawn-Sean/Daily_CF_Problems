#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD 998244353
using namespace std;

int n, K, A[MAXN + 5], B[MAXN + 5];

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);

    if (K == 0) { printf("%d\n", n); return 0; }

    long long base = 0;
    for (int i = 1; i <= n; i++) base = (base + 1LL * A[i] * B[i]) % MOD;
    base = power(base, K - 1);

    long long smA = 0;
    for (int i = 1; i <= n; i++) smA = (smA + A[i]) % MOD;
    long long smB = 0;
    for (int i = 1; i <= n; i++) smB = (smB + B[i]) % MOD;
    printf("%lld\n", smA * smB % MOD * base % MOD);
    return 0;
}
