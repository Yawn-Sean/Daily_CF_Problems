#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,x;
    std::cin>>n>>x;
    std::vector e(n+1,std::vector<int>());
    for(int i=0;i<n-1;i++){
        int u,v;
        std::cin>>u>>v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    std::vector son1(n+1,0),son2(n+1,0),l(n+1,0);
    auto dfs=[&](this auto &&self,int u,int fu,int w)->void{
        son1[u]=w;
        l[u]=0;
        for(auto &v:e[u]){
            if(v==fu){
                continue;
            }
            self(v,u,w+1);
            l[u]=std::max(l[u],l[v]+1);
        }
    };
    auto dfs2=[&](this auto &&self,int u,int fu,int w)->void{
        son2[u]=w;
        for(auto &v:e[u]){
            if(v==fu){
                continue;
            }
            self(v,u,w+1);
        }
    };
    dfs(1,0,0);
    dfs2(x,0,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(son1[i]>son2[i]){
            ans=std::max(ans,(son1[i]+l[i])*2);
        }
    }
    std::cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
