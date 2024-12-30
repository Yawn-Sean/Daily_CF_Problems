/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

struct DSU{
    std::vector<int> p, sz,mi;
    DSU(int n): p(n), sz(n, 1),mi(n,1e9){
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
        mi[x]=std::min(mi[x],mi[y]);
        return 1;
    }
    int size(int x){
        return sz[find(x)];
    }
};

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<std::array<int,3>> boom(n);
    std::vector<int> q;
    for(auto &[x,y,t]:boom) std::cin>>x>>y>>t;
    DSU dsu(n+1);
    for(int i=0;i<n;i++) q.pb(i),dsu.mi[i]=boom[i][2];

    sort(all(q),[&](auto l,auto r){
        if(boom[l][0]!=boom[r][0]) return boom[l][0]<boom[r][0];
        return boom[l][1]<boom[r][1];
    });
    for(int i=1;i<n;i++){
        auto [lx,ly,lt]=boom[q[i-1]];
        auto [rx,ry,rt]=boom[q[i]];
        bool flag=0;
        if(lx==rx and std::abs(ly-ry)<=k) flag=1;
        if(flag) dsu.merge(q[i-1],q[i]);
    }
    sort(all(q),[&](auto l,auto r){
        if(boom[l][1]!=boom[r][1]) return boom[l][1]<boom[r][1];
        return boom[l][0]<boom[r][0];
    });

    for(int i=1;i<n;i++){
        auto [lx,ly,lt]=boom[q[i-1]];
        auto [rx,ry,rt]=boom[q[i]];
        bool flag=0;
        if(ly==ry and std::abs(lx-rx)<=k) flag=1;
        if(flag) dsu.merge(q[i-1],q[i]);
    }


    std::vector<int> ans;
    for(int i=0;i<n;i++){
        if(dsu.find(i)==i) ans.pb(dsu.mi[i]);
    }
    sort(all(ans),std::greater<>());
    for(int i=0;i<(int)ans.size();i++){
        if(i==(int)ans.size()-1 or ans[i+1]<=i){
            std::cout<<i<<"\n";
            return;
        }
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
