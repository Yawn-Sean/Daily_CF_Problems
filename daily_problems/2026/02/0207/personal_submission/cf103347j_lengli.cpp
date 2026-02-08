#include <iostream>

using namespace std;

typedef long long ll;

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    ll p, x, y, a;
    if (!(cin >> p >> x >> y >> a)) return 0;

    ll l = p - 1;
    ll inv_l = power(l, p - 2, p); 
    ll xk = x % p;
    ll ans = 0;

    for (ll k = 1; k <= l && k <= a; ++k) {
        ll inv_xk = power(xk, p - 2, p);
        ll target = (y * inv_xk % p - k % p + p) % p;
        ll i = (__int128)target * inv_l % p;
        ll max_val = (a - k) / l;
        if (max_val >= i) {
            ans += (max_val - i) / p + 1;
        }
        xk = (__int128)xk * x % p;
    }

    cout << ans << endl;
    return 0;
}
