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
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> eg(n);
    std::vector<int> rd(n);
    std::vector<int> tp(n);
    for(int i=0;i<n;i++) std::cin>>tp[i];
    for(int i=0;i<m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[v].pb(u);
        rd[u]++;
    }
    std::priority_queue<std::array<int,2>,std::vector<std::array<int,2>>,std::greater<>> q;
    std::priority_queue<std::array<int,2>> p;

    for(int i=0;i<n;i++){
        if(!rd[i]){
            q.push({tp[i],i});
        }
    }

    int res=0;

    while(q.size()){
        if(q.top()[0]==1){
            res++;
            while(q.size()){
                auto [c,x]=q.top();
                q.pop();
                for(auto v:eg[x]){
                    rd[v]--;
                    if(!rd[v]) p.push({tp[v],v});
                }
            }
            while(p.size()){
                auto [c,x]=p.top();
                if(!c) break;
                p.pop();
                for(auto v:eg[x]){
                    rd[v]--;
                    if(!rd[v]) p.push({tp[v],v});
                }
            }
            while(p.size()){
                auto t=p.top();
                p.pop();
                q.push(t);
            }
        }else{
            auto [c,x]=q.top();
            q.pop();
            for(auto v:eg[x]){
                rd[v]--;
                if(!rd[v]) q.push({tp[v],v});
            }
        }
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
