#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e6 + 3;

i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
i64 mod_inverse(i64 a, i64 m) {
    return qpow(a, m - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    i64 n, c;
    cin >> n >> c;
    // C(n, n + c)

    i64 p1 = 1, p2 = 1;
    for (int i = 1; i <= n; i++) {
        p1 = (p1 * (n + c - i + 1)) % mod;
        p2 = (p2 * i) % mod;
    }

    i64 ans = 1ll * p1 * mod_inverse(p2, mod) % mod;
    cout << (ans+mod-1)%mod << '\n';
    return 0;
}