/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
    }
    std::vector<int> res,st(n+2,0);
    auto dfs=[&](auto self,int u,int fa)->void{
        if(st[u]) return;
        st[u]=1;
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
        }
        res.pb(u);
    };
    for(int i=1;i<=n;i++){
        if(!st[i]) dfs(dfs,i,0);
    }
    for(auto x:res) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
