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
    std::vector<int> c(n+2);
    std::vector<std::vector<int>> eg(n+2);

    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }

    auto dfs=[&](auto self,int u,int fa,int ffa)->void{
        int idx=1;
        for(auto x:eg[u]){
            if(x==fa) continue;
            while(idx==c[fa] or idx==c[u]) idx++;
            c[x]=idx;
            idx++;
        }
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u,fa);
        }

    };

    c[1]=1;

    dfs(dfs,1,0,0);

    std::cout<<*std::max_element(all(c))<<"\n";
    for(int i=1;i<=n;i++) std::cout<<c[i]<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
