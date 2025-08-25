#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n,m,x1,y1,x2,y2;
    cin>>n>>m>>x1>>y1>>x2>>y2;
    
    ll min_x=max(1-x1,1-x2),max_x=min(n-x1,n-x2);
    ll min_y=max(1-y1,1-y2),max_y=min(m-y1,m-y2);

    ll x=max(0ll,max_x-min_x+1);
    ll y=max(0ll,max_y-min_y+1);

    ll s=x*y;
    ll dx=llabs(x1-x2),dy=llabs(y1-y2);

    ll covx=max(0ll,x-dx);
    ll covy=max(0ll,y-dy);
    ll covs=covx*covy;
    ll ans=n*m-2*s+covs;
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
