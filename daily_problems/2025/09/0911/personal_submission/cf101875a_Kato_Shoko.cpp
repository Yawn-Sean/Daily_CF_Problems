#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e6 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    ll g=n,w=k;
    while(w>0&&g>1){
        if(w%g==0){
            w--;
            continue;
        }
        ll d=gcd(g,w);
        ans+=w*(g-d);
        g=d;
        w--;
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
