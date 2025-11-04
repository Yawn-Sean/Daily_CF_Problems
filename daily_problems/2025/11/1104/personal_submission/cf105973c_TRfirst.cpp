#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int mod = 998244353;


vector<ll> fac(1000005);
vector<ll> ans(1000005);

ll ksm(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1) res = (res * n) % mod;
        n = (n * n) % mod;
        k >>= 1;
    }
    return res;
}

ll C(ll n, ll m) {
    ll inv = (fac[m] * fac[m]) % mod;
    return (fac[n] * ksm(inv, mod - 2)) % mod;
}

void solve(){
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i <= 1e6; i++) fac[i] = (fac[i - 1] * i) % mod;
    for (int i = 1; i <= 1000000; i++) {
        if (!(i & 1)) ans[i] ^= C(i, i / 2);
        ans[i] ^= 1;
        ans[i] ^= ans[i - 1];
    }
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}