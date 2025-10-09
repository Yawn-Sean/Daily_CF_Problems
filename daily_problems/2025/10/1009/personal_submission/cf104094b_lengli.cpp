/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define int long long

constexpr int M=1000000007;
int n,m;
std::vector<std::array<int,2>> eg[200010];

std::array<std::vector<int>,2> dijkstra(int S){
    std::vector<int> dist(n+2,-1),cnt(n+2,0);
    std::vector<bool> st(n+2,0);
    std::priority_queue<std::array<int,2>,std::vector<std::array<int,2>>,std::greater<std::array<int,2>>> q;
    q.push({0,S});dist[S]=0;cnt[S]=1;
    while(q.size()){
        auto t=q.top();
        q.pop();
        if(st[t[1]]) continue;
        st[t[1]]=1;
        for(auto [x,w]:eg[t[1]]){
            if(dist[x]==-1 or dist[x]>t[0]+w){
                dist[x]=t[0]+w;
                cnt[x]=cnt[t[1]];
                q.push({dist[x],x});
            }else if(dist[x]==t[0]+w){
                cnt[x]+=cnt[t[1]];
                cnt[x]%=M;
            }
        }
    }
    return {dist,cnt};
}

void solve(){
    int S,T,L;
    std::cin>>n>>m>>S>>T>>L;
    for(int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        eg[u].pb({v,w});
        eg[v].pb({u,w});
    }

    auto [ds,cs]=dijkstra(S);
    auto [dt,ct]=dijkstra(T);

    if(ds[T]==L){
        std::cout<<cs[T]<<"\n";
        return;
    }

    if(ds[T]>L){
        std::cout<<0<<"\n";
        return;
    }

    int res=0;

    for(int u=1;u<=n;u++){
        if(u==T) continue;
        if(ds[u]==-1 or ds[u]+dt[u]!=ds[T]) continue;
        for(auto [v,w]:eg[u]){
            if(dt[v]==-1) continue;
            if(ds[u]+w+dt[v]==L){
                res=(1ll*res+(1ll*cs[u]*ct[v])%M)%M;
            }
        }
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
