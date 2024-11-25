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
    DSU dsu(n+2);
    std::vector<int> ne(n+2);
    for(int i=1;i<=n;i++) ne[i]=i+1;
    for(int i=1;i<=q;i++){
        int op,u,v;
        std::cin>>op>>u>>v;
        if(op==1) dsu.merge(u,v);
        else if(op==2){
            for(int i=u;i<=v;){
                int x=i,y=ne[i];
                if(y>v) break;
                dsu.merge(x,y);
                ne[x]=ne[v];
                i=y;
            }
        }else{
            std::cout<<(dsu.same(u,v) ? "YES" : "NO")<<"\n";
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
