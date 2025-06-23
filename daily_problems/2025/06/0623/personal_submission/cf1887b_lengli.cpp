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
    int n,t;
    std::cin>>n>>t;
    std::vector<std::vector<std::array<int,2>>> eg(n+2);
    for(int i=1;i<=t;i++){
        int m;
        std::cin>>m;
        for(int j=1;j<=m;j++){
            int u,v;
            std::cin>>u>>v;
            eg[u].pb({v,i});
            eg[v].pb({u,i});
        }
    }
    int k;
    std::cin>>k;
    std::vector<std::vector<int>> tm(t+2);
    for(int i=1;i<=k;i++){
        int x;
        std::cin>>x;
        tm[x].pb(i);
    }

    std::vector<int> dis(n+2,-1),st(n+2,0);
    std::priority_queue<std::array<int,2>,std::vector<std::array<int,2>>,std::greater<>> q;
    q.push({0,1});
    dis[1]=0;

    auto find=[&](int x,int v)->int{
        auto it=std::upper_bound(all(tm[x]),v)-tm[x].begin();
        if(it<0 or it>=tm[x].size()) return -1;
        if(tm[x][it]<=v) return -1;
        return tm[x][it];
    };

    while(q.size()){
        auto [d,u]=q.top();
        q.pop();
        if(st[u]) continue;
        st[u]=1;
        for(auto [v,id]:eg[u]){
            int nd=find(id,d);
            if(nd==-1) continue;
            if(dis[v]==-1 or nd<dis[v]){
                dis[v]=nd;
                q.push({nd,v});
            }
        }
    }
    std::cout<<dis[n]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
