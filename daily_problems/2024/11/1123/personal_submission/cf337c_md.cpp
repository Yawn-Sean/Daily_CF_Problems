// 1123
#include <bits/stdc++.h>

using i64 = long long;
const i64 MOD = 1e9 + 9;

// Y Y Y ... Y_k - 1, X
// Y Y Y ... Y_k - 1, X
// Y Y Y ... Y_k - 1, X
// ...
// rows: n / k
// incorrect: (n - m)
// candouble = rows - incorrect = n / k - n + m

template <typename T>
T modpow(T base, T exp, T mod) {
    T result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    i64 rows = n / k;
    i64 incorrect = n - m;
    i64 candouble = std::max(0ll, rows - incorrect);
    i64 tail = m - candouble * k;

    std::cout << (MOD + k * (modpow(2ll, candouble + 1, MOD) - 2) % MOD + tail) % MOD << '\n';


    return 0;
}