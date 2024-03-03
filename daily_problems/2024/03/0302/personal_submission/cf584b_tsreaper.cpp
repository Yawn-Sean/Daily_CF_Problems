#include <bits/stdc++.h>
#define MOD ((int) 1e9 + 7)
using namespace std;

long long power(long long a, long long b) {
    long long y = 1;
    for (; b ;b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

int main() {
    long long n; scanf("%lld", &n);
    printf("%lld\n", (power(3, n * 3) - power(7, n) + MOD) % MOD);
    return 0;
}
