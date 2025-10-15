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
    std::vector<std::vector<std::array<int,2>>> eg(n+2);
    std::vector<int> st(n+2),f(n+2);

    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb({v,1});
        eg[v].pb({u,-1});
    }

    int res=0;

    auto dfs=[&](auto self,int u,int fa,int len)->void{
        if(st[u]){
            res=std::gcd(res,len-f[u]);
            return;
        }
        st[u]=1;
        f[u]=len;
        for(auto [x,v]:eg[u]){
            self(self,x,u,len+v);
        }
    };

    for(int i=1;i<=n;i++){
        if(!st[i]){
            dfs(dfs,i,0,0);
        }
    }
    if(!res) res=n;
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
