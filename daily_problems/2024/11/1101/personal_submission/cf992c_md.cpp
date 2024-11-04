// 1101
#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 MOD = 1e9 + 7;

long long modpow(long long base, long long exp, long long mod) {
    long long ret = 1;
    while (exp) {
        if (exp & 1) {
            ret = ret * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return ret % MOD;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 x, k;
    std::cin >> x >> k;

    if (x == 0) {
        std::cout << 0 << '\n';
    } else {
        x %= MOD;
        std::cout << ((modpow(2, k + 1, MOD) % MOD * x) % MOD - modpow(2, k, MOD) + 1 + MOD) % MOD << '\n';
    }
    return 0;
}