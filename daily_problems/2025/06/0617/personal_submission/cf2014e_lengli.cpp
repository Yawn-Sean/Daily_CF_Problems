/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=200010;

int n,m,h;
std::vector<std::array<int,2>> eg[N];
int hv[N];

auto dijkstra(int S){
    std::vector<std::vector<i64>> dist(n+1,std::vector<i64> (2,-1));
    std::vector<std::vector<int>> st(n+1,std::vector<int> (2,0));
    std::priority_queue<std::array<i64,3>,std::vector<std::array<i64,3>>,std::greater<std::array<i64,3>>> q;
    q.push({0,0,S});
    dist[S][0]=0;
    if(hv[S]){
        q.push({0,1,S});
        dist[S][1]=0;
    }
    while(q.size()){
        auto [len,is,u]=q.top();
        q.pop();
        if(st[u][is]) continue;
        st[u][is]=1;
        for(auto [x,w]:eg[u]){
            int nis=is|hv[x];
            i64 nlen=len+(is ? w/2 : w);
            if(dist[x][nis]==-1 or dist[x][nis]>nlen){
                dist[x][nis]=nlen;
                q.push({nlen,nis,x});
            }
        }
    }
    return dist;
}

void solve(){
    std::cin>>n>>m>>h;
    for(int i=1;i<=h;i++){
        int x;
        std::cin>>x;
        hv[x]=1;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        eg[u].pb({v,w});
        eg[v].pb({u,w});
    }
    auto r1=dijkstra(1),rn=dijkstra(n);
    
    i64 res=1000000000000000000;

    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                if(r1[i][j]!=-1 and rn[i][k]!=-1){
                    i64 ans=std::max(r1[i][j],rn[i][k]);
                    res=std::min(res,ans);
                }
            }
        }
        
    }
    if(res==1000000000000000000) res=-1;
    std::cout<<res<<"\n";
    
    for(int i=1;i<=n;i++){
        eg[i].clear();
        hv[i]=0;
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
