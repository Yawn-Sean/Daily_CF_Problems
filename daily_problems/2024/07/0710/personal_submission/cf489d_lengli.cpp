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
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<=m;i++){
        int a,b;
        std::cin>>a>>b;
        eg[a].pb(b);
    }
    long long res=0;
    auto bfs=[&](int u){
        std::vector<int> st(n+2,0),cnt(n+2,0);
        st[u]=1;
        std::queue<int> q;
        for(auto x:eg[u]) q.push(x);
        while(q.size()){
            auto t=q.front();
            q.pop();
            for(auto x:eg[t]){
                if(st[x]) continue;
                cnt[x]++;
            }
        }
        for(int i=1;i<=n;i++){
            res+=1ll*(cnt[i]-1)*cnt[i]/2;
        }
    };

    for(int i=1;i<=n;i++) bfs(i);
    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
