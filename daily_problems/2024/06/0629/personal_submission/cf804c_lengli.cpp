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
    std::vector<std::vector<int>> eg(n+2),pt(n+2);
    for(int i=1;i<=n;i++){
        int k;
        std::cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            std::cin>>x;
            pt[i].pb(x);
        }
    }
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }
    std::vector<int> res(m+2,-1);
    auto dfs=[&](auto self,int u,int f)->void{
        std::set<int> s;
        for(auto x:pt[u]){
            if(res[x]!=-1) s.insert(res[x]);
        }
        int cnt=1;
        for(auto x:pt[u]){
            if(res[x]!=-1) continue;
            while(s.count(cnt)) cnt++;
            res[x]=cnt;
            s.insert(res[x]);
        }
        for(auto x:eg[u]){
            if(x==f) continue;
            self(self,x,u);
        }
    };

    dfs(dfs,1,0);
    std::set<int> s;
    for(int i=1;i<=m;i++){
        if(res[i]==-1) res[i]=1;
        s.insert(res[i]);
    }
    std::cout<<s.size()<<"\n";
    for(int i=1;i<=m;i++) std::cout<<res[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
