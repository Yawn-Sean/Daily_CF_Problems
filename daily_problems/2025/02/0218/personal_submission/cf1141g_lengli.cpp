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
    int n,k;
    std::cin>>n>>k;
    std::vector<std::vector<std::array<int,2>>> eg(n+2);
    std::vector<int> res(n+2,-1);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb({v,i});
        eg[v].pb({u,i});
    }

    std::vector<int> b;
    for(int i=1;i<=n;i++) b.pb(i);
    sort(all(b),[&](auto l,auto r){
        return eg[l].size()>eg[r].size();
    });

    std::vector<int> st(n+2,0);

    for(int i=0;i<k;i++) st[b[i]]=1;

    int ans=eg[b[k]].size();

    std::cout<<ans<<"\n";

    auto dfs=[&](auto self,int u,int fa,int col)->void{
        int tt=col ? col : 1;
        int now=0;
        for(auto [v,id]:eg[u]){
            if(v==fa) continue;
            now++;
            if(now==col) now++;
            res[id]=st[u] ? tt : now;
            self(self,v,u,st[u] ? tt : now);
            
        }
    };  

    dfs(dfs,1,0,0);

    for(int i=1;i<n;i++) std::cout<<res[i]<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
