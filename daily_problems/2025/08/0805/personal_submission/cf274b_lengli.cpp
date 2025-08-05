/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<n;i++){
        int a,b;
        std::cin>>a>>b;
        eg[a].pb(b);
        eg[b].pb(a);
    }
    std::vector<int> c(n+2);
    for(int i=1;i<=n;i++) std::cin>>c[i];

    std::vector<i64> g(n+2),f(n+2);

    auto dfs=[&](auto self,int u,int fa)->void{
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
            f[u]=std::max(f[u],f[x]);
            g[u]=std::max(g[u],g[x]);
        }
        if(c[u]+f[u]-g[u]<0) 
            f[u]-=c[u]+f[u]-g[u];
        else g[u]+=c[u]+f[u]-g[u];
    };

    dfs(dfs,1,0);

    std::cout<<g[1]+f[1]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
