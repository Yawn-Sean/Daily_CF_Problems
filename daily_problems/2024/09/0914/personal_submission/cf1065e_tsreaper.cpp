#include <bits/stdc++.h>
#define MAXM ((int) 2e5)
#define MOD 998244353
using namespace std;

int B[MAXM + 10];
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
    int n, m, A; scanf("%d%d%d", &n, &m, &A);
    for (int i = 1; i <= m; i++) scanf("%d", &B[i]);

    long long inv2 = power(2, MOD - 2);
    ans = power(A, n - 2 * B[m]);
    for (int i = 1; i <= m; i++) {
        int len = B[i] - B[i - 1];
        long long t = (power(A, 2 * len) + power(A, len)) * inv2 % MOD;
        ans = ans * t % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
