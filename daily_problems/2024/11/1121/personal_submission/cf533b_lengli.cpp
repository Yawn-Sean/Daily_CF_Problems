/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;

constexpr i64 inf=1e18;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> eg(n+2);
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++){
        int p;
        std::cin>>p>>a[i];
        if(p!=-1){
            eg[p].pb(i);
            eg[i].pb(p);
        }
    }

    std::vector<std::vector<i64>> f(n+2,std::vector<i64> (2,-inf));


    auto dfs=[&](auto self,int u,int fa)->void{
        f[u][0]=0;
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
            i64 j=f[u][1],o=f[u][0];
            f[u][0]=std::max(f[u][0],f[x][1]+j);
            f[u][1]=std::max(f[u][1],f[x][1]+o);
            f[u][0]=std::max(f[u][0],f[x][0]+o);
            f[u][1]=std::max(f[u][1],f[x][0]+j);
        }
        f[u][1]=std::max(f[u][1],f[u][0]+a[u]);
    };

    dfs(dfs,1,0);
    std::cout<<std::max(f[1][0],f[1][1])<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
