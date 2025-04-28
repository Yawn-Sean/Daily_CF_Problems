#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
    ll tot = accumulate(a.begin(), a.end(), 0ll);
    ll ans = min(tot / 3, tot - mx);
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
