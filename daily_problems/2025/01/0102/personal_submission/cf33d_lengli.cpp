/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct LCA{
    std::vector<int> dep;
    std::vector<std::vector<int>> eg,fa;
    int m;
    void init(int n){
        m=log(n)/log(2)+1;
        eg.clear(),dep.clear(),fa.clear();
        eg.resize(n+1),dep.resize(n+1,0);
        fa.resize(n+1,std::vector<int> (m+1,0));
    }
    
    void dfs(int u, int f) {
        for (int i = 1; i <= m; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto j:eg[u]) {
            if (j == f) continue;
            fa[j][0] = u;
            dep[j] = dep[u] + 1;
            dfs(j, u);
        }
    }
    int lca(int a, int b) {
        if (dep[a] < dep[b]) std::swap(a, b);
        for (int i = m; i >= 0; i--) {
            if (dep[a] - (1 << i) >= dep[b]) a = fa[a][i];
        }
        if (a == b) return a;
        for (int i = m; i >= 0; i--) {
            if (fa[a][i] != fa[b][i]) {
                a = fa[a][i];
                b = fa[b][i];
            }
        }
        return fa[a][0];
    }
}tr;

void solve(){
    int n,m,q;
    std::cin>>n>>m>>q;
    std::vector<std::array<int,2>> pt(n+2);
    for(int i=1;i<=n;i++) std::cin>>pt[i][0]>>pt[i][1];
    std::vector<std::array<int,3>> wl(m+2);
    for(int i=1;i<=m;i++) std::cin>>wl[i][0]>>wl[i][1]>>wl[i][2];

    std::vector<int> id(n+2);

    auto pt_is_in=[&](int x,int y)->bool{
        i64 dx=wl[y][1]-pt[x][0];
        i64 dy=wl[y][2]-pt[x][1];
        i64 r=wl[y][0];
        if(r*r>=dx*dx+dy*dy) return 1;
        return 0;
    };

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            if(pt_is_in(i,j)){
                if(!id[i]) id[i]=j;
                else if(wl[j][0]<wl[id[i]][0]) id[i]=j;
            }
    }

    std::vector<int> near(m+2);

    auto cc_is_in=[&](int x,int y)->bool{
        i64 dx=wl[y][1]-wl[x][1];
        i64 dy=wl[y][2]-wl[x][2];
        i64 r=wl[x][0]+wl[y][0];
        if(dx*dx+dy*dy>=r*r) return 0;
        return wl[x][0]<wl[y][0];
    };

    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i==j) continue;
            if(cc_is_in(i,j)){
                if(!near[i]) near[i]=j;
                else if(wl[j][0]<wl[near[i]][0]) near[i]=j;
            }
        }
    }

    tr.init(m+2);
    for(int i=1;i<=m;i++){
        if(near[i]){
            tr.eg[i].pb(near[i]);
            tr.eg[near[i]].pb(i);
        }else{
            tr.eg[0].pb(i);
            tr.eg[i].pb(0);
        }
    }
    tr.dfs(0,-1);

    for(int i=0;i<q;i++){
        int u,v;
        std::cin>>u>>v;
        u=id[u],v=id[v];
        int t=tr.lca(u,v);
        std::cout<<tr.dep[u]+tr.dep[v]-2*tr.dep[t]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
