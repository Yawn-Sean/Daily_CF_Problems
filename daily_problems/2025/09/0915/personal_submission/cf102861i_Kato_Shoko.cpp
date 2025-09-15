#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

vector<int>g[N];
int n;

il pair<ll,ll> dfs(ll u){
    if(g[u].size()==0)return {1,1};
    ll x=0,y=1;
    for(auto v:g[u]){
        auto [x0,y0]=dfs(v);
        x=(y*x0%mod+x*y0%mod)%mod;
        y=y*y0%mod;
    }
    y=(y+x)%mod;
    return {x,y};
}

il void solve(){
    cin>>n;
    for(int i=2;i<=n;i++){
        ll x;
        cin>>x;
        g[x].push_back(i);
    }    

    cout<<dfs(1).second;
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
