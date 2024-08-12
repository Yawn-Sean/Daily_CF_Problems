/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

struct DSU{
    std::vector<int> p, sz,add;
    DSU(int n): p(n), sz(n, 0),add(n,0){
        std::iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        return x == p[x] ? x : p[x]=find(p[x]);
    }
    int sum(int x){
        return x == p[x] ? add[x] : add[x]+sum(p[x]);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        if(size(x) < size(y)) std::swap(x,y);
        sz[x] += sz[y];
        p[y] = x;
        add[y]-=add[x];
        return 1;
    }
    int size(int x){
        return sz[find(x)];
    }
};

void solve(){
    int n,m;
    std::cin>>n>>m;
    DSU dsu(n*2+5);
    for(int i=1;i<=n;i++) dsu.sz[i]=1;
    for(int i=1;i<=m;i++){
        int u,v;
        std::string s;
        std::cin>>u>>v>>s;
        if(s=="crewmate") dsu.merge(u,v),dsu.merge(u+n,v+n);
        else dsu.merge(u,v+n),dsu.merge(u+n,v);
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(dsu.find(i)==dsu.find(i+n)){
            std::cout<<"-1"<<"\n";
            return;
        }
        res+=std::max(dsu.size(i),dsu.size(i+n));
        dsu.sz[dsu.find(i)]=0;
        dsu.sz[dsu.find(i+n)]=0;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
