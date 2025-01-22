/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;

void solve(){
    int n,x,y;
    std::cin>>n>>x>>y;

    std::vector<std::vector<int>> eg(n+2);
    std::vector<int> st(n+2,0);

    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }

    std::vector<int> tmp_path;

    auto dfs=[&](auto self,int u,int fa)->void{
        tmp_path.pb(u);
        if(u==y){
            for(auto c:tmp_path) st[c]=1;
            return;
        }
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
        }
        tmp_path.pop_back();
    };
    
    dfs(dfs,x,-1);

    st[x]=st[y]=0;

    int l=0,r=0;

    auto dfs1=[&](auto self,int u,int fa,int &cnt,int t){
        if(st[u] or u==t) return;
        cnt++;
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u,cnt,t);
        }
    };

    dfs1(dfs1,x,-1,l,y);
    dfs1(dfs1,y,-1,r,x);

    i64 res=1ll*n*(n-1);
    res-=1ll*l*r;
    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
