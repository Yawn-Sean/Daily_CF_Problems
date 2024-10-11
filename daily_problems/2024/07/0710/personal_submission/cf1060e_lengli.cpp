/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }
    long long res=0,cnt=0;
    std::vector<int> dep(n+2,0);
    auto dfs=[&](auto self,int u,int fa)->int{
        int sz=1;
        dep[u]=dep[fa]+1;
        for(auto x:eg[u]){
            if(x==fa) continue;
            sz+=self(self,x,u);
        }
        res+=1ll*(n-sz)*sz;
        if(dep[u]&1) cnt++;
        return sz;
    };
    dfs(dfs,1,0);
    res+=1ll*(n-cnt)*cnt;
    std::cout<<(res/2);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
