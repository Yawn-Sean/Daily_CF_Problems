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
    int n,k;
    std::cin>>n>>k;
    std::vector<int> st(n+2);
    for(int i=1;i<=k;i++){
        int x;
        std::cin>>x;
        st[x]=1;
    }

    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }

    std::vector<int> dep(n+2,1),up(n+2);

    std::vector<int> path;

    auto dfs=[&](auto self,int u,int fa)->void{
        path.pb(u);
        for(auto x:eg[u]){
            if(x==fa) continue;
            dep[x]=dep[u]+1;
            if(st[x]) {
                if(dep[x]==2) up[x]=x;
                else up[x]=path[dep[x]/2];
            }
            self(self,x,u);
        }
        path.pop_back();
    };

    dfs(dfs,1,0);

    std::vector<int> hv(n+2);
    for(int i=1;i<=n;i++) hv[up[i]]++;

    int res=0,flag=1;
    
    auto dfs1=[&](auto self,int u,int fa)->void{
        if(u!=1 and eg[u].size()==1){
            if(!hv[u]) flag=0;
            else res++;
            return;
        }
        if(!flag) return;
        if(hv[u]){
            res++;
            return;
        }
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
        }
    };

    dfs1(dfs1,1,0);

    std::cout<<(flag ? res : -1)<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
