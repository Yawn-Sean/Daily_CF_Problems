#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int mod = 998244353;



ll ksm(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1) res = (res * n) % mod;
        n = (n * n) % mod;
        k >>= 1;
    }
    return res;
}
vector<ll> base(1e5 + 5);

void solve(){
    int n;
    cin >> n;
    cout << (base[n] * (n + 1)) % mod << endl;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for (int i = 1; i <= 1e5; i++) {
        base[i] = (base[i - 1] + ksm(i + 1, mod - 2)) % mod;
    }
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}