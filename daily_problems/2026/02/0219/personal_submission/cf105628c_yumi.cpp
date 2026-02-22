#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

i128 gcd_(i128 a, i128 b){
    return b == 0 ? a : gcd_(b, a % b);
}
i128 lcm_(i128 a, i128 b){
    return a / gcd_(a, b) * b;
}
void solve(){
    int n;
    ll l, r, k;
    cin >> n >> l >> r >> k;
    vector<ll> a(n);
    i128 res = 1, bound = 1e12;
    ll mn = LLONG_MAX;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        res = min(bound, lcm_(res, a[i]));
        mn = min(mn, a[i]);
    }
    if(mn <= k || r < k){
        cout << "-1\n";
        return;
    }
    ll ans = (l - k + res - 1) / res * res + k;
    if(ans >= l && ans <= r){
        cout << ans << "\n";
    }else{
        cout << "-1\n";
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}