// 0511
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

// power mod
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

    i64 n, m, a, Q;
    std::cin >> n >> m >> a >> Q;

    i64 p = 1ll;
    i64 phi = 0ll;
    do {
        p = p * a % Q;
        ++phi;
    } while (p != 1);

    int MX = m + 1;
    vector<i64> comb(n), fac(MX), inv_fac(MX);
    comb[0] = 1 % phi;
    
    fac[0] = 1 % phi;
    for (int i = 1; i < MX; i++) {
        fac[i] = fac[i - 1] * i % phi;
    }

    inv_fac[MX - 1] = modpow(fac[MX - 1], phi - 2, phi);
    for (int i = MX - 1; i > 0; i--) {
        inv_fac[i - 1] = inv_fac[i] * i % phi;
    }

    auto get_comb = [&fac, &inv_fac, phi](int n, int k) -> i64 {
        if (n < k || k < 0) return 0;
        return fac[n] * inv_fac[n - k] % phi * inv_fac[k] % phi;
    };

    for (int i = 1; i < n; ++i) {
        comb[i] = comb[i - 1] + get_comb(m, i);
    }

    std::reverse(begin(comb), end(comb));
    for (i64 i = 0; i < n; ++i) {
        cout << modpow(a, comb[i], Q) << " \n"[i == n - 1];
    }
    
    return 0;
}