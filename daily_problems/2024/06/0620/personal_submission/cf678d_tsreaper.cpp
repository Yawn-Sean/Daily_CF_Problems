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
    long long A, B, n, X; scanf("%lld%lld%lld%lld", &A, &B, &n, &X);
    if (A == 1) { printf("%lld\n", (X + n % MOD * B) % MOD); return 0; }
    long long ans1 = power(A, n) * X % MOD;
    long long ans2 = (power(A, n) - 1 + MOD) * power(A - 1, MOD - 2) % MOD * B % MOD;
    printf("%lld\n", (ans1 + ans2) % MOD);
    return 0;
}
