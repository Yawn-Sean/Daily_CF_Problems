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
    long long x, K; scanf("%lld%lld", &x, &K);
    if (x == 0) printf("0\n");
    else printf("%lld\n", (x % MOD * power(2, K + 1) - power(2, K) + 1 + MOD) % MOD);
    return 0;
}
