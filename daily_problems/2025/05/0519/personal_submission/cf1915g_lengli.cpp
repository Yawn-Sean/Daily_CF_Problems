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

#define int long long

std::vector<std::array<int,2>> eg[N];
int n,m;
int k[N];

std::vector<std::vector<int>> dijkstra(int S){
    std::vector<std::vector<int>> dist(n+1,std::vector<int> (N,-1));
    std::vector<std::vector<int>> st(n+1,std::vector<int> (N,0));
    std::priority_queue<std::array<int,3>,std::vector<std::array<int,3>>,std::greater<std::array<int,3>>> q;
    q.push({0,S,k[S]});dist[S][k[S]]=0;
    while(q.size()){
        auto [v,id,c]=q.top();
        q.pop();
        if(st[id][c]) continue;
        st[id][c]=1;
        for(auto [x,w]:eg[id]){
            if(dist[x][c]==-1 or dist[x][c]>v+w*c){
                dist[x][c]=v+w*c;
                q.push({dist[x][c],x,c});
            }
            if(dist[x][k[x]]==-1 or dist[x][k[x]]>v+w*c){
                dist[x][k[x]]=v+w*c;
                q.push({dist[x][k[x]],x,k[x]});
            }
        }
    }
    return dist;
}


void solve(){
    std::cin>>n>>m;
    for(int i=1;i<=n;i++) eg[i].clear();
    for(int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        eg[u].pb({v,w});
        eg[v].pb({u,w});
    }
    for(int i=1;i<=n;i++) std::cin>>k[i];

    auto res=dijkstra(1);
    i64 ans=1e18;
    for(int i=1;i<=1000;i++){
        if(res[n][i]!=-1) ans=std::min(ans,res[n][i]);
    }
    std::cout<<ans<<"\n";
}

signed main(){
    fastio;

    int T;
    std::cin>>T;
    while(T--) solve();

    return 0;
}
