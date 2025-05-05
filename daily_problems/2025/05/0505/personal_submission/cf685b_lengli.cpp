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
    int n,q;
    std::cin>>n>>q;
    std::vector<int> p(n+2);
    std::vector<std::vector<int>> eg(n+2);
    for(int i=2;i<=n;i++){
        int x;
        std::cin>>x;
        p[i]=x;
        eg[x].pb(i);
        eg[i].pb(x);
    }
    std::vector<int> res(n+2,-1),sz(n+2,0),mx(n+2,0);

    auto dfs=[&](auto self,int u,int fa)->void{
        sz[u]=1;
        for(auto v:eg[u]){
            if(v==fa) continue;
            self(self,v,u);
            sz[u]+=sz[v];
            mx[u]=std::max(mx[u],sz[v]);
        }
        if(!mx[u]) res[u]=u;
        for(auto v:eg[u]){
            if(v==fa) continue;
            int x=res[v];
            while(1){
                if(mx[x]*2<=sz[u] and (sz[u]-sz[x])*2<=sz[u]){
                    res[u]=x;
                    break;
                }
                if(x==u) break;
                x=p[x];
            }
        }
    };

    dfs(dfs,1,-1);
    while(q--){
        int x;
        std::cin>>x;
        std::cout<<res[x]<<"\n";
    }
}   

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
