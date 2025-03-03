/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

std::vector<int> dijkstra(int S,int n,std::vector<std::vector<int>> &eg){
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
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> eg(n+2),reg(n+2);
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        reg[v].pb(u);
    }
    int k;
    std::cin>>k;
    std::vector<int> st(n+2,0);
    std::vector<int> a(k+2);
    for(int i=1;i<=k;i++) std::cin>>a[i];

    auto d=dijkstra(a[k],n,reg);

    int r1=0,r2=0;
    for(int i=1;i<k;i++){
        int u=a[i],v=a[i+1];
        int f1=0,f2=0;
        for(auto x:eg[u]){
            if(d[x]<d[v]) f1=1;
            else if(v!=x and d[v]==d[x]) f2=1;
        }
        if(f1) r1++;
        else if(f2) r2++;
    }
    std::cout<<r1<<" "<<r1+r2<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
