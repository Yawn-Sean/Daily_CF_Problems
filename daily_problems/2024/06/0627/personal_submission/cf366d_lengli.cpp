/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=1010,inf=1e9;

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
    int n,m;
    std::cin>>n>>m;
    std::vector<std::array<int,4>> edge(m);
    std::vector<int> q;
    for(auto &[u,v,l,r]:edge){
        std::cin>>u>>v>>l>>r;
        q.pb(l);
    }
    sort(all(q));
    q.erase(unique(all(q)),q.end());
    sort(all(edge),[&](auto ll,auto rr){
        return ll[3]>rr[3];
    });
    int res=0;
    for(auto x:q){
        DSU dsu(n+2);
        for(auto [u,v,l,r]:edge){
            if(l<=x and r>=x){
                dsu.merge(u,v);
                if(dsu.same(1,n)){
                    res=std::max(res,r-x+1);
                    break;
                }
            }
        }
        
    }
    if(res) std::cout<<res;
    else std::cout<<"Nice work, Dima!";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
