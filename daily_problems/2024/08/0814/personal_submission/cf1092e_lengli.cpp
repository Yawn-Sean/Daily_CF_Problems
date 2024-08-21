/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=1010;

int n,m;
std::vector<int> eg[N];
int d[N],up[N],st[N];

std::array<int,2> get_tree_diameter(int u){
    int c=0,l=u,r=u,mid=u;
    auto dfs=[&](auto self,int u, int fa)->void{
        st[u]=1;
        for(auto v:eg[u]) {
            if(v==fa) continue;
            d[v]=d[u]+1;
            up[v]=u;
            if(d[v]>d[c]) c=v;
            self(self,v,u);
        }
    };
    dfs(dfs,u,0);
    d[c]=0;l=c;
    dfs(dfs,c,0);r=c;mid=c;
    while(d[mid]>(d[c]+1)/2){
        mid=up[mid];
    }
    if(d[c]==0) l=r=mid=u;
    return {d[c],mid}; 
}

void solve(){
    std::cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }

    std::vector<std::array<int,2>> q,res; 
    for(int i=1;i<=n;i++){
        if(!st[i]) q.pb(get_tree_diameter(i));
    }
    sort(all(q),std::greater<>());
    for(int i=1;i<q.size();i++){
        int u=q[i][1],v=q[0][1];
        eg[u].pb(v);
        eg[v].pb(u);
        res.pb({u,v});
    }
    for(int i=1;i<=n;i++) d[i]=0;
    std::cout<<get_tree_diameter(1)[0]<<"\n";
    for(auto [u,v]:res) std::cout<<u<<" "<<v<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
