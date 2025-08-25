/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=1010;

int n,m;

std::vector<i64> dijkstra(int S,std::vector<std::vector<std::array<int,2>>> &eg){
    std::vector<i64> dist(n+1,-1);
    std::vector<bool> st(n+1,0);
    std::priority_queue<std::array<i64,2>,std::vector<std::array<i64,2>>,std::greater<std::array<i64,2>>> q;
    q.push({0,S});dist[S]=0;
    while(q.size()){
        auto t=q.top();
        q.pop();
        if(st[t[1]]) continue;
        st[t[1]]=1;
        for(auto [x,w]:eg[t[1]]){
            if(dist[x]==-1 or dist[x]>t[0]+w){
                dist[x]=t[0]+w;
                q.push({dist[x],x});
            }
        }
    }
    return dist;
}

void solve(){
    std::cin>>n>>m;
    int s,t;
    std::cin>>s>>t;

    std::vector<std::vector<std::array<int,2>>> eg(n+2);

    for(int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        eg[u].pb({v,w});
        eg[v].pb({u,w});
    }

    std::vector<int> len(n+2),c(n+2);
    for(int i=1;i<=n;i++) std::cin>>len[i]>>c[i];

    std::vector<std::vector<i64>> d(n+2);

    for(int i=1;i<=n;i++) d[i]=dijkstra(i,eg);


    for(int i=1;i<=n;i++){
        eg[i].clear();
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(d[i][j]!=-1 and d[i][j]<=len[i]){
                eg[i].pb({j,c[i]});
            }
        }
    }
    auto res=dijkstra(s,eg);

    std::cout<<res[t]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
