#include <bits/stdc++.h>
#define MOD ((int) 1e9 + 9)
using namespace std;

long long power(long long a, long long b) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    int n, m, K; scanf("%d%d%d", &n, &m, &K);
    int x = n / K * (K - 1) + n % K;
    if (x >= m) { printf("%d\n", m); return 0; }
    int t = m - x;
    long long w = (power(2, t + 1) - 2 + MOD) % MOD * K % MOD;
    w = (w + (m - t * K)) % MOD;
    printf("%lld\n", w);
    return 0;
}
