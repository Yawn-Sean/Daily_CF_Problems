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
    std::vector<std::vector<std::array<int,2>>> eg(n+2);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb({v,i});
        eg[v].pb({u,i});
    }

    std::vector<std::vector<int>> res(n+2);
    int len=0;
    auto dfs=[&](auto self,int u,int fa,int id)->void{
        int t=0;
        for(auto [x,k]:eg[u]){
            if(x==fa) continue;
            if(t==id) t++;
            len=std::max(len,t);
            res[t].pb(k);
            self(self,x,u,t);
            t++;
        }
    };

    dfs(dfs,1,0,-1);
    std::cout<<len+1<<"\n";
    for(int i=0;i<=len;i++){
        std::cout<<res[i].size()<<" ";
        for(auto x:res[i]) std::cout<<x<<" ";
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
