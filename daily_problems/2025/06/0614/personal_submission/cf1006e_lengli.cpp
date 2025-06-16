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
    int n,q;
    std::cin>>n>>q;
    std::vector<std::vector<int>> eg(n+2);
    for(int i=2;i<=n;i++){
        int u;
        std::cin>>u;
        eg[u].pb(i);
        eg[i].pb(u);
    }

    std::vector<int> dfn_in(n+2),dfn_out(n+2);
    int timespace=0;

    std::vector<int> res;

    for(auto &x:eg) std::sort(all(x));

    auto dfs=[&](auto self,int u,int fa)->void{
        dfn_in[u]=timespace;
        res.pb(u);
        timespace++;
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
        }
        dfn_out[u]=timespace;
    };

    dfs(dfs,1,0);

    while(q--){
        int x,k;
        std::cin>>x>>k;
        int len=dfn_out[x]-dfn_in[x];
        if(len<k) std::cout<<"-1"<<"\n";
        else std::cout<<res[dfn_in[x]+k-1]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
