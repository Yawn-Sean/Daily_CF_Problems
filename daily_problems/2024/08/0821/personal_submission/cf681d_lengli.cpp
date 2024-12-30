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
    std::vector<int> rd(n+2,0);
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        rd[v]++;
    }
    std::vector<int> a(n+2,0);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    bool flag=1;
    std::queue<int> res;
    auto dfs=[&](auto self,int u,int fa){
        if(!flag) return;
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
        }
        if(a[u]==u) res.push(u);
        else if(a[u]!=a[fa]) flag=0;
    };

    for(int i=1;i<=n;i++){
        if(!rd[i]){
            dfs(dfs,i,0);
        }
    }
    if(!flag) std::cout<<"-1"<<"\n";
    else{
        std::cout<<res.size()<<"\n";
        while(res.size()){
            std::cout<<res.front()<<"\n";
            res.pop();
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
