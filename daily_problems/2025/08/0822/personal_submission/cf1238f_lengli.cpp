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
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }

    std::vector<int> f(n+2);

    int res=0;
    auto dfs=[&](auto self,int u,int fa)->void{
        int mx0=0,mx1=0;
        int son=0;
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
            f[u]=std::max(f[u],f[x]);
            if(f[x]>mx0) mx1=mx0,mx0=f[x];
            else if(f[x]>mx1) mx1=f[x];
            son++;
        }
        f[u]+=1+std::max(0,son-1);
        int v=std::max(son-1-(fa==0),0);
        res=std::max(res,mx0+mx1+1+v);
        
    };

    dfs(dfs,1,0);

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
