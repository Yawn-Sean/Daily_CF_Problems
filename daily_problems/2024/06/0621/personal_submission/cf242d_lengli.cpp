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
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }
    std::vector<int> a(n+2),res,st(n+2,0),b(n+2,0);
    std::queue<int> q;
    for(int i=1;i<=n;i++) {
        std::cin>>a[i];
        if(a[i]==0) q.push(i); 
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(st[t]) continue;
        st[t]=1;
        res.pb(t);
        b[t]++;
        for(auto x:eg[t]){
            b[x]++;
            if(b[x]==a[x]){
                q.push(x);
            }
        }
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
