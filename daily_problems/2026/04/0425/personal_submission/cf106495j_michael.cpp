#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return qpow(x, MOD - 2);
}

void solve(){
    int n;
    cin >> n;
    if(n == 1 || n == 2){
        cout << 0 << '\n';
        return;
    }
    ll oc = (n + 1) / 2,ec = n / 2;
    ll c2 = oc * (oc - 1) % MOD * inv(2) % MOD * ec % MOD;
    ll c3 = ec * (ec - 1) % MOD * (ec - 2) % MOD * inv(6) % MOD;
    
    cout << (c2 + c3) % MOD << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}