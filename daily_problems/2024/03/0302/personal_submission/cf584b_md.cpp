// 0302
#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 MOD = 1e9 + 7;

template <typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % modulus;
        }   
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;
    std::cout << (MOD + modpow(27ll, n, MOD) - modpow(7ll, n, MOD)) % MOD << '\n';

    return 0;
}