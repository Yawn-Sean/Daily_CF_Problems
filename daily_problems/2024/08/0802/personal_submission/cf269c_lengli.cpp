/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;

    std::vector<std::vector<std::array<int,3>>> eg(n+2);
    std::vector<long long> res(m+2,-1),sum_flow(n+2,0),sum(n+2,0);
    for(int i=1;i<=m;i++){
        int a,b,c;
        std::cin>>a>>b>>c;
        eg[a].pb({b,c,i});
        eg[b].pb({a,c,-i});
        sum_flow[a]+=c;
        sum_flow[b]+=c;
    }

    std::queue<int> q;
    q.push(1);
    while(q.size()){
        auto u=q.front();
        q.pop();
        for(auto [v,w,fx]:eg[u]){
            if(res[std::abs(fx)]!=-1) continue;
            if(fx<0) res[-fx]=1,sum[v]+=w;
            else res[fx]=0,sum[v]+=w;
            if(sum[v]*2==sum_flow[v]){
                if(v!=n) q.push(v);
            }
        }
    }
    for(int i=1;i<=m;i++) std::cout<<res[i]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
