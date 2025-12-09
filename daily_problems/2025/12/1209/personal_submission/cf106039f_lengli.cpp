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
    int n,m,k;
    std::cin>>n>>m>>k;

    std::vector<std::vector<std::array<int,2>>> eg(n+k+2);
    for(int i=1;i<=m;i++){
        int u,v,c;
        std::cin>>u>>v>>c;
        eg[u].pb({v,c});
        eg[v].pb({u,c});
    }

    for(int i=1;i<=n;i++){
        int cnt;
        std::cin>>cnt;
        for(int j=0;j<cnt;j++){
            int tp,c;
            std::cin>>tp>>c;
            eg[i].pb({n+tp,c});
            eg[n+tp].pb({i,0});
        }
    }

    int len=n+k+2;
    std::vector<i64> dist(len,-1);
    std::vector<int> st(len,0);
    std::priority_queue<std::array<i64,2>,std::vector<std::array<i64,2>>,std::greater<std::array<i64,2>>> q;
    q.push({0,1});dist[1]=0;
    while(q.size()){
        auto [d,u]=q.top();
        q.pop();
        if(st[u]) continue;
        st[u]=1;
        for(auto [v,c]:eg[u]){
            if(dist[v]==-1 or dist[v]>d+c){
                dist[v]=d+c;
                q.push({dist[v],v});
            }
        }
    }
    std::cout<<dist[n]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
