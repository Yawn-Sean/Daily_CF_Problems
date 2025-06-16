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
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> eg(n+2);
    std::vector<int> rd(n+2);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
        rd[v]++,rd[u]++;
    }

    std::priority_queue<std::array<int,2>,std::vector<std::array<int,2>>,std::greater<>> q;
    std::vector<int> v(n+2,1);
    for(int i=1;i<=n;i++){
        if(eg[i].size()==1) q.push({v[i],i});
    }
    while(q.size()){
        auto [cnt,u]=q.top();
        q.pop();
        if(cnt!=v[u]) continue;
        for(auto x:eg[u]){
            if(!v[x]) continue;
            if(v[x]<v[u]) continue;
            v[x]+=v[u];
            v[u]=0;
            rd[x]--;
            if(rd[x]==1) q.push({v[x],x});
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(v[i]) cnt++;
    }
    std::cout<<(cnt==1 ? "YES" : "NO")<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
