#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    const int mod = 1e9+7;
    auto pows = [&](ll a, ll b)->ll{
        ll res = 1;
        while (b){
            if (b&1) res = res*a%mod;
            a = a*a%mod;
            b >>= 1;
        }
        return res;
    };
    auto mo = [&](ll x)->ll{
        return (x%mod + mod)%mod;
    };

    ll x, k;
    cin >> x >> k;
    if (x == 0) return cout << 0 << "\n", void();
    const int inv2 = pows(2, mod-2);

    ll res = mo(x-inv2) * pows(2, k) % mod;
    res = (res + inv2) % mod;

    cout << 2*res%mod << "\n";
}
