// 0528
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int MOD = 998244353;
constexpr int MX = 5001;

i64 q_pow(i64 x, int n) {
    i64 res = 1;
    for (; n > 0; n /= 2) {
        if (n % 2) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

i64 fac[MX], inv_fac[MX];
i64 comb(int n, int k) {
    if (n < k || k < 0) {
        return 0;
    }
    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
}

i64 factorial(int x) {
    return fac[x];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    auto init = [] {
        fac[0] = 1;
        for (int i = 1; i < MX; i++) {
            fac[i] = fac[i - 1] * i % MOD;
        }
        inv_fac[MX - 1] = q_pow(fac[MX - 1], MOD - 2);
        for (int i = MX - 1; i > 0; i--) {
            inv_fac[i - 1] = inv_fac[i] * i % MOD;
        }
        return 0;
    }();

    auto calc = [](int x, int y) -> i64 {
        i64 ret = 0;
        for (int i = 0; i <= min(x, y); ++i) {
            ret = (ret + comb(x, i) * comb(y, i) % MOD * factorial(i) % MOD) % MOD;
        }
        return ret;
    };

    cout << calc(a, b) * calc(b, c) % MOD * calc(c, a) % MOD << endl;
    return 0;
}