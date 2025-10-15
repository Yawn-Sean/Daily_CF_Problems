/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=100010,inf=2e9;

int n,m;
std::vector<std::array<int,2>> eg[N];
int onPath[N];
int pa[N];

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
        for(auto [x,w]:eg[t[1]]){
            if(dist[x]==-1 or dist[x]>t[0]+w){
                dist[x]=t[0]+w;
                pa[x]=t[1];
                q.push({dist[x],x});
            }
        }
    }
    return dist;
}

void solve(){
    std::cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,t;
        std::cin>>u>>v>>t;
        eg[u].pb({v,t});
        eg[v].pb({u,t});
    }
    auto d1=dijkstra(1);
    auto dn=dijkstra(n);

    int res=d1[n],ans=inf;

    int pos=n;
    while(1){
        onPath[pos]=1;
        if(pos==1) break;
        int bk=pos;
        for(auto [x,w]:eg[pos]){
            if(d1[x]+w==d1[pos]){
                pos=x;
                break;
            }
        }
        if(pos==bk) break;
    }

    for(int i=1;i<=n;i++){
        if(d1[i]==-1) continue;
        for(auto [x,w]:eg[i]){
            if(dn[x]==-1) continue;
            if(onPath[i] and onPath[x] and (pa[i]==x or pa[x]==i)) continue;
            ans=std::min(ans,d1[i]+dn[x]+w);
            
        }
    }
    if(ans==inf) std::cout<<"-1"<<"\n";
    else std::cout<<res+ans<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
