/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=100010;

int n,m,k;
int volt[N];
std::vector<int> eg[N];
int S,T;

std::vector<int> dijkstra(int limit){
    std::vector<int> dist(n+1,-1);
    std::priority_queue<std::array<int,2>,std::vector<std::array<int,2>>,std::greater<std::array<int,2>>> q;
    q.push({0,S});dist[S]=0;
    while(q.size()){
        auto t=q.top();
        q.pop();
        for(auto x:eg[t[1]]){
            if(dist[x]==-1 or dist[x]>t[0]+1){
                if(t[0]+1>limit) continue;
                dist[x]=t[0]+1;
                if(volt[x]) dist[x]=0;
                q.push({dist[x],x});
            }
        }
    }
    return dist;
}

void solve(){
    std::cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int x;
        std::cin>>x;
        volt[x]=1;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }
    std::cin>>S>>T;
    int l=1,r=n;

    auto check=[&](int x){
        auto ans=dijkstra(x);
        return ans[T]!=-1;
    };

    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(check(r)) std::cout<<r<<"\n";
    else std::cout<<"-1"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
