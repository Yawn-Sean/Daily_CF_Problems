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
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    DSU dsu(n+2);

    for(int i=1;i<=m;i++){
        int l,r;
        std::cin>>l>>r;
        dsu.merge(l,r);
    }

    std::vector<std::vector<int>> eg(n+2);

    for(int i=1;i<=n;i++){
        eg[dsu.find(i)].pb(a[i]);
    }

    int res=0;

    for(int i=1;i<=n;i++){
        auto &q=eg[i];
        int cnt=q.size(),mx=0;
        sort(all(q));
        int la=-1,count=0;
        for(auto x:q){
            if(la==-1) la=x,count=1;
            else if(la==x) count++;
            else{
                mx=std::max(mx,count);
                la=x;count=1;
            }
        }
        if(la!=-1) mx=std::max(mx,count);
        res+=cnt-mx;
    }

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
