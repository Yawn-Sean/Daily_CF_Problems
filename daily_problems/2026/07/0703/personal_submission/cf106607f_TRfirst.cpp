#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int mod = 998244353;



ll ksm(ll n, ll k) {
    n %= mod;
    ll res = 1;
    while (k) {
        if (k & 1) res = (res * n) % mod;
        n = (n * n) % mod;
        k >>= 1;
    }
    return res;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    m++;
    vector<ll> dp(70);
    int c = 0;
    for (int i = 60; i >= 0; i--) {
        for (int j = 59; j >= 0; j--) {
            dp[j + 1] += dp[j];
            dp[j + 1] %= mod;
        }
        if (m >> i & 1) dp[c]++, c++;
        dp[c] %= mod;
    }
    ll ans = 0;
    for (int i = 0; i <= 60; i++) {
        ans += (dp[i] * ksm(n, i));
        ans %= mod;
    } 
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}
