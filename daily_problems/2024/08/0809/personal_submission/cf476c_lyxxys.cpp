#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 2e5, mod = 1e9+7, inf = 1e9;

void solve(){
    ll a, b;
    cin >> a >> b;
    auto mos = [&](int x)->int{
        return (x%mod + mod) % mod;
    };

    int res = 0, sum = b*(b-1)/2%mod;
    for (ll i = 1; i <= a; ++ i){
        ll ans = sum*(i*b%mod + 1) % mod;
        (res += ans) %= mod;
    }

    cout << res << "\n";
}
