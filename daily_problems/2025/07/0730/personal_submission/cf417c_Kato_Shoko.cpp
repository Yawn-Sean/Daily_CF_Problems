#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 998244353, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;;i++){
        ll need=i*(i*3+1)/2;
        if(need>n)break;
        if((n-need)%3)continue;
        ans++;
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
