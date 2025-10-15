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
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<std::vector<int>> eg(n+2),reg(n+2);
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        reg[v].pb(u);
    }
    std::vector<int> st(n+2),rst(n+2);
    auto dfs=[&](auto self,int u)->void{
        if(st[u]) return;
        st[u]=1;
        for(auto v:eg[u]){
            self(self,v);
        }
    };
    auto rdfs=[&](auto self,int u)->void{
        if(rst[u]) return;
        rst[u]=1;
        if(a[u]==1) return;
        for(auto v:reg[u]){
            self(self,v);
        }
    };
    for(int i=1;i<=n;i++){
        if(a[i]==1) dfs(dfs,i);
        else if(a[i]==2) rdfs(rdfs,i);
    }
    for(int i=1;i<=n;i++){
        std::cout<<(st[i]&&rst[i])<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
