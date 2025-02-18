#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m, A[MAXN + 10], B[MAXN + 10];
long long ans = 0;

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    
    long long inv = power(m, MOD - 2), now = 1;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 0 && B[i] == 0) {
            long long t = 1LL * m * (m - 1) / 2 % MOD;
            ans = (ans + now * t % MOD * inv % MOD * inv) % MOD;
            now = now * inv % MOD;
        } else if (A[i] == 0) {
            ans = (ans + now * (m - B[i]) % MOD * inv) % MOD;
            now = now * inv % MOD;
        } else if (B[i] == 0) {
            ans = (ans + now * (A[i] - 1) % MOD * inv) % MOD;
            now = now * inv % MOD;
        } else {
            if (A[i] > B[i]) ans = (ans + now) % MOD;
            if (A[i] != B[i]) break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
