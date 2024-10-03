/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

struct DSU{
    std::vector<int> p, sz;
    std::vector<std::vector<int>> eg;
    DSU(int n): p(n), sz(n, 1){
        std::iota(p.begin(), p.end(), 0);
        eg.resize(n);
        for(int i=0;i<n;i++) eg[i].pb(i);
    }
    int find(int x){
        return x == p[x] ? x : p[x]=find(p[x]);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        if(size(x) < size(y)) std::swap(x,y);
        for(auto t:eg[y]) eg[x].pb(t);
        sz[x] += sz[y];
        p[y] = x;
        return 1;
    }
    int size(int x){
        return sz[find(x)];
    }
};

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(n+2,std::vector<char> (m+2));
    DSU dsu(n+m+10);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            std::cin>>g[i][j];
            if(g[i][j]=='=') dsu.merge(i,n+j);
        }
    std::vector<std::vector<int>> d(n+m+10,std::vector<int> (n+m+10,0));
    std::vector<int> rd(n+m+10,0),f(n+m+10,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='=') continue;
            else{
                int u=dsu.find(i),v=dsu.find(j+n);
                if(u==v) continue;
                if(g[i][j]=='>' and !d[v][u]){
                    d[v][u]=1;
                    rd[u]++;
                }else if(g[i][j]=='<' and !d[u][v]){
                    d[u][v]=1;
                    rd[v]++;
                }
            }
        }
    }
    std::queue<int> q;
    for(int i=1;i<=n+m;i++){
        if(dsu.find(i)==i){
            if(!rd[i]) q.push(i);
        }
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=1;i<=n+m;i++){
            if(dsu.find(i)==i and d[t][i]){
                f[i]=std::max(f[i],f[t]+1);
                rd[i]--;
                if(!rd[i]) q.push(i);
            }
        }
    }

    for(int i=1;i<=n+m;i++){
        if(dsu.find(i)==i){
            for(auto x:dsu.eg[i]) f[x]=f[i];
        }
    }

    bool flag=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]=='=' and f[i]!=f[n+j]) flag=0;
            if(g[i][j]=='>' and f[i]<=f[n+j]) flag=0;
            if(g[i][j]=='<' and f[i]>=f[n+j]) flag=0;
        }
    }

    if(flag){
        std::cout<<"Yes"<<"\n";
        for(int i=1;i<=n;i++) std::cout<<f[i]<<" ";std::cout<<"\n";
        for(int i=n+1;i<=n+m;i++) std::cout<<f[i]<<" ";
    }else std::cout<<"No"<<"\n";

    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
