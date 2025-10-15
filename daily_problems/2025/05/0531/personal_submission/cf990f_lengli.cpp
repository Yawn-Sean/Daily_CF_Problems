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
    std::vector<int> s(n+2);

    int sum=0;

    for(int i=1;i<=n;i++){
        std::cin>>s[i];
        sum+=s[i];
    }

    if(sum){
        std::cout<<"Impossible"<<"\n";
        return;
    }
    std::cout<<"Possible"<<"\n";

    
    int m;
    std::cin>>m;

    std::vector<std::vector<std::array<int,2>>> eg(n+2);

    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb({v,i});
        eg[v].pb({u,-i});
    }

    std::vector<int> st(n+2),f(m+2);

    auto dfs=[&](auto self,int u,int fa,int id)->void{
        st[u]=1;
        for(auto [v,t]:eg[u]){
            if(!st[v]){
                self(self,v,u,t);
            }
        }
        if(s[u]){
            if(id<0) f[-id]-=s[u];
            else f[id]+=s[u];
            s[fa]+=s[u];
            s[u]=0;
        }
    };

    dfs(dfs,1,0,0);

    for(int i=1;i<=m;i++) std::cout<<f[i]<<"\n";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
