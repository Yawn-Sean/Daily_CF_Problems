/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=110;
std::vector<int> eg[N];
int n,m;

std::array<std::vector<i64>,2> dijkstra(int S){
    std::vector<i64> dist(n+1,-1),f(n+1,0);
    std::priority_queue<std::array<int,2>,std::vector<std::array<int,2>>,std::greater<std::array<int,2>>> q;
    q.push({0,S});
    dist[S]=0;
    f[S]=1;
    while(q.size()){
        auto t=q.top();
        q.pop();
        for(auto x:eg[t[1]]){
            if(dist[x]==-1 or dist[x]>t[0]+1){
                dist[x]=t[0]+1;
                f[x]=f[t[1]];
                q.push({(int)dist[x],x});
            }else if(dist[x]==t[0]+1){
                f[x]+=f[t[1]];
            }
        }
    }
    return {dist,f};
}

void solve(){
    std::cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }
    auto [d1,f1]=dijkstra(1);
    auto [dn,fn]=dijkstra(n);

    i64 res=0;
    for(int i=1;i<=n;i++){
        i64 s=0;
        for(auto x:eg[i]){
            if(d1[i]+1+dn[x]==d1[n] and d1[i]!=-1 and dn[x]!=-1){
                s+=f1[i]*fn[x];
            }else if(dn[i]+1+d1[x]==dn[1] and d1[x]!=-1 and dn[i]!=-1){
                s+=fn[i]*f1[x];
            }
        }
        res=std::max(res,s);
    }
    double out=(double)res/(double)f1[n];
    std::cout<<std::fixed<<std::setprecision(12)<<out<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
