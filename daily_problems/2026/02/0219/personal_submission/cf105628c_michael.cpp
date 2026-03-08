#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a,ll b) {return b == 0 ? a : gcd(b,a % b);}

void solve(){
    ll n,l,r,k;
    cin >> n >> l >> r >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n ;++i){
        cin >> arr[i];
    }
    if(k > r){
        cout << "-1\n";
        return;
    }
    for(auto e : arr){
        if(e <= k){
            cout << "-1\n";
            return;
        }
    }
    if(l <= k && k <= r){
        cout << k << '\n';
        return;
    }
    ll limit = r - k;
    ll L = 1;
    for(auto e : arr){
        ll g = gcd(e,L);
        if(L / g > limit / e){
            cout << "-1\n";
            return;
        }
        L = L * (e / g);
    }
    ll t_min = (l - k + L - 1) / L;
    ll ans = t_min * L + k;
    cout << (ans >= l && ans <= r ? ans : -1) << '\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}