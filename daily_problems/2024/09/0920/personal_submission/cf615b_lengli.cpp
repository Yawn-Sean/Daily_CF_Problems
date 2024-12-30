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
    std::vector<int> rd(n+2,0),f(n+2,1);
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        if(u>v) std::swap(u,v);
        eg[u].pb(v);
        rd[u]++,rd[v]++;
    }
    for(int i=1;i<=n;i++){
        for(auto x:eg[i]){
            f[x]=std::max(f[x],f[i]+1);
        }
    }
    long long res=0;
    for(int i=1;i<=n;i++){
        res=std::max(res,1ll*f[i]*rd[i]);
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
