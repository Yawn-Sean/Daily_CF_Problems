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
    int n;
    std::string a,b;
    std::cin>>n>>a>>b;
    DSU dsu(30);
    std::vector<std::array<char,2>> res;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) continue;
        int l=a[i]-'a',r=b[i]-'a';
        if(dsu.same(l,r)) continue;
        dsu.merge(l,r);
        res.pb({a[i],b[i]});
    }
    std::cout<<res.size()<<"\n";
    for(auto [x,y]:res) std::cout<<x<<" "<<y<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
