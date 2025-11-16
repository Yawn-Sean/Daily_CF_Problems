#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll floordiv(ll a, ll b) {
    if (a >= 0) return a / b;
    return - ((-a + b - 1) / b);
}

ll isqrt_ll(ll x) {
    if (x < 0) return -1;
    long double fx = (long double)x;
    ll r = (ll)floor(sqrt(fx));
    while ((r+1) > 0 && ( (__int128)(r+1) * (r+1) ) <= x) ++r;
    while (r > 0 && ( (__int128)r * r ) > x) --r;
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, xl, yl, W, H;
    if (!(cin >> n >> xl >> yl >> W >> H)) return 0;
    ll xr = xl + W;
    ll yr = yl + H;
    xl = xl - 1;
    yl = yl - 1;
    
    ll g = 0;
    const int LIMIT = 1000000;
    for (ll i = 1; i <= LIMIT; ++i) {
        ll v = n - i * i;
        if (v < 0) break;
        ll w = isqrt_ll(v);
        if (i > w) break;
        if (w * w == v) {
            g = std::gcd(g, i);
            g = std::gcd(g, w);
        }
    }
    
    ll ans = 0;
    if (g) {
        ll t = 2 * g;
        ll a1 = floordiv(xr, t) - floordiv(xl, t);
        ll a2 = floordiv(yr, t) - floordiv(yl, t);
        ll b1 = floordiv(xr - g, t) - floordiv(xl - g, t);
        ll b2 = floordiv(yr - g, t) - floordiv(yl - g, t);
        ans += a1 * a2;
        ans += b1 * b2;
    } else {
        if (xl < 0 && 0 <= xr && yl < 0 && 0 <= yr) ans += 1;
    }
    
    cout << ans << '\n';
    return 0;
}
