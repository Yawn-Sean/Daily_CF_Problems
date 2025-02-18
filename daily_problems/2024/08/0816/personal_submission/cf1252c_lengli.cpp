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
    DSU(int n): p(n), sz(n, 1),add(n,0){
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
    int n,q;
    std::cin>>n>>q;
    std::vector<int> r(n+2),c(n+2);
    for(int i=1;i<=n;i++) std::cin>>r[i];
    for(int i=1;i<=n;i++) std::cin>>c[i];
    DSU a(n+2),b(n+2);

    for(int i=2;i<=n;i++){
        int nw=r[i]&1,la=r[i-1]&1;
        if(nw==la) a.merge(i,i-1);
        nw=c[i]&1,la=c[i-1]&1;
        if(nw==la) b.merge(i,i-1);
    }

    while(q--){
        int sx,sy,ex,ey;
        std::cin>>sx>>sy>>ex>>ey;
        std::cout<<(a.same(sx,ex) and b.same(sy,ey) ? "YES" : "NO")<<"\n"; 
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
