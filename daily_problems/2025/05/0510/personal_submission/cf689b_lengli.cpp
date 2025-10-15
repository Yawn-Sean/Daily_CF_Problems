/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=500010;

int n;
std::vector<int> eg[N];

std::vector<int> dijkstra(int S){
    std::vector<int> dist(n+1,-1);
    std::vector<bool> st(n+1,0);
    std::priority_queue<std::array<int,2>,std::vector<std::array<int,2>>,std::greater<std::array<int,2>>> q;
    q.push({0,S});dist[S]=0;
    while(q.size()){
        auto t=q.top();
        q.pop();
        if(st[t[1]]) continue;
        st[t[1]]=1;
        for(auto x:eg[t[1]]){
            if(dist[x]==-1 or dist[x]>t[0]+1){
                dist[x]=t[0]+1;
                q.push({dist[x],x});
            }
        }
    }
    return dist;
}

void solve(){
    std::cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        eg[i].pb(x);
        if(i!=n){
            eg[i].pb(i+1);
            eg[i+1].pb(i);
        }
    }
    auto d=dijkstra(1);
    for(int i=1;i<=n;i++){
        std::cout<<d[i]<<" ";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
