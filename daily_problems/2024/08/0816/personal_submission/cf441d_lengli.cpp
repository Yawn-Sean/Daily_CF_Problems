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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    DSU dsu(n+2);
    auto get=[&](){
        std::vector<int> st(n+2,0);
        dsu=DSU(n+2);
        for(int i=1;i<=n;i++){
            if(!st[i]){
                st[i]=1;
                int u=a[i];
                while(u!=i){
                    st[u]=1;
                    dsu.merge(u,i);
                    u=a[u];
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;i++){
            if(dsu.find(i)==i) res++;
        }
        return res;
    };

    int m;
    std::cin>>m;
    int cnt=get();
    std::vector<std::array<int,2>> res;
    while(cnt!=n-m){
        int l=-1,r=-1;
        for(int i=1;i<=n and l==-1;i++){
            for(int j=i+1;j<=n and l==-1;j++){
                if(cnt>n-m and !dsu.same(i,j)) l=i,r=j;
                if(cnt<n-m and dsu.same(i,j)) l=i,r=j;
            }
        }
        res.pb({l,r});
        std::swap(a[l],a[r]);
        cnt=get();
    }
    std::cout<<res.size()<<"\n";
    for(auto [l,r]:res) std::cout<<l<<" "<<r<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
