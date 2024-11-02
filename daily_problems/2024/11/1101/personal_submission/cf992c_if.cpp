#pragma Gcc optimize(3)
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod = 1e9 + 7;

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

void solve() {
    ll x ,k;
    cin >> x >> k;
    if(x == 0){
        cout << 0 << endl;
        return;
    }
    ll ans = (quickPow(2, k, mod) * ((2 * x - 1) % mod) + 1) % mod;
    cout << ans << endl;
    return;


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
