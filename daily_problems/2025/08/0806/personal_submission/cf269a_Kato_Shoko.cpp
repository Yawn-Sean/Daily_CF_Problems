#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e6 + 5, mod = 998244353, inf = LLONG_MAX;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    ll n;
    cin>>n;
    ll ans=0;
    while(n--){
        ll k,a;
        cin>>k>>a;
        ans=max(ans,k+1);
        while(a>1){
            a=(a+3)/4;
            k++;
        }
        ans=max(ans,k);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {
    
        solve();

    }

    return 0;
}
