/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

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
    bool flag=1;
    std::vector<int> res;

    auto dfs=[&](auto self,int u,int fa)->int{
        int sz=1;
        for(auto [x,id]:eg[u]){
            if(x==fa) continue;
            int cnt=self(self,x,u);
            if(cnt==3) res.pb(id);
            else sz+=cnt;
        }
        if(sz>3) flag=0;
        return sz;
    };

    auto sz=dfs(dfs,1,0);
    if(sz!=3) flag=0;
    if(flag){
        std::cout<<res.size()<<"\n";
        for(auto x:res) std::cout<<x<<" ";
        std::cout<<"\n";
    }else std::cout<<"-1"<<"\n";

}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
