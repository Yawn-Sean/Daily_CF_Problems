#include <bits/stdc++.h>
#define MOD ((int) 1e9 + 7)
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
    int n, m, K, R, C; scanf("%d%d%d%d%d", &n, &m, &K, &R, &C);
    int xa, ya, xb, yb; scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    if (xa == xb && ya == yb) printf("%lld\n", power(K, 1LL * n * m));
    else printf("%lld\n", power(K, 1LL * n * m - 1LL * R * C));
    return 0;
}
