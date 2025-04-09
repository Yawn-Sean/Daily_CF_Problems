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
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }
    std::vector<int> res={1};
    int x,root=1;
    auto dfs=[&](auto self,int u,int fa)->bool{
        if(u==root) return 1;
        for(auto v:eg[u]){
            if(v==fa) continue;
            if(self(self,v,u)){
                res.pb(u);
                return 1;
            }
        }
        return 0;
    };
    while(std::cin>>x){
        dfs(dfs,x,0);
        root=x;
    }
    dfs(dfs,1,0);
    if(res.size()!=2*n-1) std::cout<<"-1"<<"\n";
    else{
        for(auto x:res) std::cout<<x<<" ";
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
