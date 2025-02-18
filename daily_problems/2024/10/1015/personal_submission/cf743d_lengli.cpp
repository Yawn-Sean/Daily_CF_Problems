/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr long long inf=1e18;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2,0);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }

    std::vector<std::array<long long,2>> q(n+2);
    for(int i=1;i<=n;i++) q[i]={-inf,-inf};
    auto add=[&](int id,long long x){
        auto &p=q[id];
        if(x>p[0]) p[1]=p[0],p[0]=x;
        else if(x>p[1]) p[1]=x;
    };

    long long res=-inf;

    std::vector<long long> sum(n+2,0);
    auto dfs1=[&](auto self,int u,int fa)->void{
        sum[u]=a[u];
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
            sum[u]+=sum[x];
        }
    };

    dfs1(dfs1,1,0);

    auto dfs2=[&](auto self,int u,int fa)->void{
        for(auto x:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
            add(u,q[x][0]);
        }
        if(q[u][0]!=-inf and q[u][1]!=-inf){
            res=std::max(res,q[u][0]+q[u][1]);
        }
        add(u,sum[u]);
    };

    dfs2(dfs2,1,0);

    if(res==-inf) std::cout<<"Impossible"<<"\n";
    else std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
