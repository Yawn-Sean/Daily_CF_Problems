#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 3e5 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>a(m+1);
    for(int i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second;
    }
    
    ll ans=0;
    
    ll d=a[1].first;
    ans=a[1].second+d-1;
    for(int i=2;i<=m;i++){
        auto [perd,perh]=a[i-1];
        auto [d,h]=a[i];
        ans=max({ans,h,perh});
        if(abs(h-perh)<=d-perd){
            ans=max(ans,max(h,perh)+(d-perd-abs(h-perh))/2);
        }else{
            cout<<"IMPOSSIBLE";
            return ;
        }
    }
    d=a[m].first;
    ans=max(ans,a[m].second+n-d);
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
