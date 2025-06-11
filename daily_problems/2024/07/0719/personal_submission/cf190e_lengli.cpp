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
    std::vector<std::vector<int>> eg(n+2),res;
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }
    std::set<int> s;
    for(int i=1;i<=n;i++) s.insert(i),sort(all(eg[i]));
    std::vector<int> st(n+2,0);

    auto bfs=[&](int u){
        std::queue<int> q;
        q.push(u);
        s.erase(u);
        std::vector<int> ans;
        while(q.size()){
            auto t=q.front();
            q.pop();
            if(st[t]) continue;
            st[t]=1;
            ans.pb(t);
            std::vector<int> cl;
            for(auto x:s){
                auto it=lower_bound(all(eg[t]),x)-eg[t].begin();
                if(it>=eg[t].size() or eg[t][it]!=x){
                    q.push(x);
                    cl.pb(x);
                }
            }
            for(auto x:cl) s.erase(x);
        } 
        res.pb(ans);  
    };

    for(int i=1;i<=n;i++){
        if(!st[i]) bfs(i);
    }

    std::cout<<res.size()<<"\n";
    for(auto x:res){
        std::cout<<x.size()<<" ";
        for(auto y:x) std::cout<<y<<" ";
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
