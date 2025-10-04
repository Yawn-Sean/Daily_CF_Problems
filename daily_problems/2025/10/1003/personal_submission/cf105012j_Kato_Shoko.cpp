#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e3 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;
    vector<ll>num(n);
    for(auto &i:num)cin>>i;
    vector<vector<int>>g(n);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll>dp1(n),dp2(n);

    auto f=[&](ll x,ll y){
        ll v=sqrt(min(x,y));
        while(v*v<min(x,y))v++;
        while(v*v>min(x,y))v--;
        return max(x,y)+v;
    };

    auto dfs1=[&](auto &self,int u,int fa)->void{
        dp1[u]=num[u];
        for(auto v:g[u]){
            if(v==fa)continue;
            self(self,v,u);
            dp1[u]=max(dp1[u],f(dp1[v],num[u]));
        }
    };

    auto dfs2=[&](auto &self,int u,int fa)->void{
        dp2[u]=max(dp2[u],num[u]);
        ll v1=dp2[u],v2=0;

        for(auto v:g[u]){
            if(v==fa)continue;
            ll nv=f(dp1[v],num[u]);
            if(nv>v1)swap(v1,v2),v1=nv;
            else if(nv>v2)v2=nv;
        }

        for(auto v:g[u]){
            if(v==fa)continue;
            ll nv=f(dp1[v],num[u]);
            if(nv==v1)dp2[v]=f(v2,num[v]);
            else dp2[v]=f(v1,num[v]);
            self(self,v,u);
        }
    };

    dfs1(dfs1,0,0);
    dfs2(dfs2,0,0);

    cout<<max(*max_element(dp1.begin(),dp1.end()),*max_element(dp2.begin(),dp2.end()));
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
