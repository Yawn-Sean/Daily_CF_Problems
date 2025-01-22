/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<std::array<int,2>>> eg(2*n+2);
    for(int i=1;i<=2*n-1;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        eg[u].pb({v,w});
        eg[v].pb({u,w});
    }
    i64 mi=0,mx=0;

    auto dfs0=[&](auto self,int u,int fa)->int{
        int sz=1;
        for(auto [x,w]:eg[u]){
            if(x==fa) continue;
            auto t=self(self,x,u);
            if(t&1) mi+=w;
            sz+=t;
        }
        return sz;
    };
    dfs0(dfs0,1,0);

    auto dfs1=[&](auto self,int u,int fa)->int{
        int sz=1;
        for(auto [x,w]:eg[u]){
            if(x==fa) continue;
            auto t=self(self,x,u);
            mx+=1ll*w*std::min(t,2*n-t);
            sz+=t;
        }
        return sz;
    };
    dfs1(dfs1,1,0);

    std::cout<<mi<<" "<<mx<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
