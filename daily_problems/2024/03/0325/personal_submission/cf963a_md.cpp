#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr ll MOD = 1e9+9;

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

template <typename T>
T modinv(T x, T modulus) {
    return modpow(x, modulus - 2, modulus);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, a, b, k;
    cin >> n >> a >> b >> k;

    string signs;
    cin >> signs;
    ll sum = 0;
    for (ll i = 0; i < k; ++i) {
        long long val = (modpow(a, n-i, MOD) % MOD * modpow(b, i, MOD) % MOD + MOD) % MOD;
        sum = (sum + (signs[i] == '+' ? 1ll : -1ll) * val % MOD + MOD) % MOD;
    }

    ll q = (modpow(b, k, MOD) % MOD * modpow(modinv(a, MOD), k, MOD) % MOD + MOD) % MOD;
    ll ret = 0ll;
    if (q == 1) {
        ret = (sum * ((n+1) / k) % MOD + MOD) % MOD;
    } else {
        ll t = (n + 1) / k;
        ret = sum * (1 - modpow(q, t, MOD) + MOD) % MOD * modinv(1 - q + MOD, MOD) % MOD;
    }
    
    cout << ret << endl;
    return 0;
}