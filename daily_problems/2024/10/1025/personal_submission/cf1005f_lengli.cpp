/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;

    std::vector<std::vector<std::array<int,2>>> eg(n+2);

    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb({v,i});
        eg[v].pb({u,i});
    }

    std::vector<std::vector<int>> pre(n+2);
    std::vector<int> dist(n+2,-1),st(n+2,0);
    std::queue<int> q;
    q.push(1);
    dist[1]=0;
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(st[t]) continue;
        st[t]=1;
        for(auto [x,id]:eg[t]){
            if(dist[x]==-1 or dist[x]>dist[t]+1){
                dist[x]=dist[t]+1;
                if(dist[x]!=-1) pre[x].clear();
                pre[x].pb(id);
                q.push(x);
            }else if(dist[x]==dist[t]+1) pre[x].pb(id);
        }
    }

    std::vector<std::vector<int>> res;

    std::vector<int> use(m+2);

    auto dfs=[&](auto self,int pos){
        if(res.size()>=k) return;
        if(pos==1){
            std::vector<int> ans;
            for(int i=1;i<=m;i++) ans.pb(use[i]);
            if(res.size()<k) res.pb(ans);
            return;
        }
        for(auto la:pre[pos]){
            use[la]=1;
            self(self,pos-1);
            use[la]=0;
        }

    };

    dfs(dfs,n);

    std::cout<<res.size()<<"\n";
    for(auto x:res){
        for(auto y:x) std::cout<<y;
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
