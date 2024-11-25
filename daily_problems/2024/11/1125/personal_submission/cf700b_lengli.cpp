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
    int n,k;
    std::cin>>n>>k;
    std::vector<int> st(n+2);
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<=k*2;i++){
        int x;
        std::cin>>x;
        st[x]=1;
    }
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }

    i64 res=0;

    auto dfs=[&](auto self,int u,int fa)->int{
        int cnt=st[u];
        for(auto x:eg[u]){
            if(x==fa) continue;
            cnt+=self(self,x,u);
        }
        int d=std::min(cnt,2*k-cnt);
        res+=d;
        return cnt;
    };

    dfs(dfs,1,0);

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
