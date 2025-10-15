/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct DSU{
    std::vector<int> p, sz;
    DSU(int n): p(n), sz(n, 1){
        std::iota(p.begin(), p.end(), 0);
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

    std::vector<std::array<int,3>> egs,egw;
    for(int i=1;i<=m;i++){
        int u,v;
        char c;
        std::cin>>u>>v>>c;
        if(c=='S') egs.pb({u,v,i});
        else egw.pb({u,v,i});
    }

    if(n%2==0){
        std::cout<<"-1"<<"\n";
        return;
    }

    int cnt=(n-1)/2;

    std::vector<int> use(egw.size(),0);

    auto check=[&](){
        DSU dsu(n+2);
        int ks=0,kw=0;
        for(auto [l,r,_]:egs) ks+=dsu.merge(l,r);
        if(ks<cnt) return 0;
        for(int j=0;auto [l,r,_]:egw){
            if(dsu.merge(l,r)){
                use[j]=1;
                kw++;
            }
            j++;
        }
        if(dsu.size(1)!=n) return 0;
        return 1;
    };
    if(!check()){
        std::cout<<"-1"<<"\n";
        return;
    }

    std::vector<int> res;
    
    auto getans=[&](){
        DSU dsu(n+2);
        int ks=0,kw=0;
        for(int i=0;i<use.size();i++){
            if(use[i]){
                dsu.merge(egw[i][0],egw[i][1]);
                res.pb(egw[i][2]);
                kw++;
            }
        }
        for(int j=0;auto [l,r,i]:egw){  
            if(!use[j] and dsu.merge(l,r)){
                res.pb(i);
                kw++;
            }
            j++;
            if(kw==cnt) break;
        }

        for(auto [l,r,i]:egs){
            if(dsu.merge(l,r)){
                res.pb(i);
                ks++;
            }
            if(ks==cnt) break;
        }

        
        
        if(ks!=cnt or kw!=cnt) return 0;
        return 1;
    };

    if(!getans()){
        std::cout<<"-1"<<"\n";
        return;
    }

    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
