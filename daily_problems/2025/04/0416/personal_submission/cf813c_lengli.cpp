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
    int n,x;
    std::cin>>n>>x;
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<=n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }

    auto dfs=[&](auto self,int u,int fa,int d,std::vector<int>& dis)->void{
        dis[u]=d;
        for(auto v:eg[u]){
            if(v==fa) continue;
            self(self,v,u,d+1,dis);
        }
    };

    std::vector<int> d1(n+2,-1),d2(n+2,-1);
    dfs(dfs,1,0,0,d1);
    dfs(dfs,x,0,0,d2);

    int res=0;
    for(int i=1;i<=n;i++){
        if(d1[i]>d2[i]){
            res=std::max(res,d1[i]*2);
        }
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
