#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0) {
        cout << 0 << "\n";
        return;
    }
    m /= n / 2 + 1;
    ll mi = INT_MAX;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (i % 2 == 0) {
            mi = min(mi, x);
        }
    }
    ll ans = min(mi, m * k);
    cout << ans << "\n";

}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
