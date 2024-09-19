// 0918
#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 MOD = 998244353;

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

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> collections(n);
    std::vector<int> cnt(1e6 + 1, 0);
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        collections[i].resize(m);
        for (auto& val : collections[i]) {
            std::cin >> val;
            ++cnt[val];
        }
    }

    // \sum_{x=1,n} \sum_{y in ax} 1/n * 1/siz[x] * cnt[y] / n
    constexpr int M = 1e6;
    std::vector<i64> fac(M + 1, 1), invfac(M + 1, 1);
    for (int i = 1; i <= M; ++i) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    }

    invfac[M] = modpow(fac[M], MOD - 2, MOD);

    for (int i = M; i >= 1; --i) {
        invfac[i - 1] = 1ll * invfac[i] * i % MOD;
    }

    auto inv = [&](int x) -> i64 {
        return 1ll * fac[x - 1] * invfac[x] % MOD;
    };

    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        for (auto v : collections[i]) {
            ans += 1ll * cnt[v] * inv(ssize(collections[i])) % MOD;
            ans %= MOD;
        }
    }

    const auto INV_N = inv(n) % MOD;
    std::cout << (ans * (INV_N * INV_N % MOD)) % MOD << '\n';

    return 0;
}