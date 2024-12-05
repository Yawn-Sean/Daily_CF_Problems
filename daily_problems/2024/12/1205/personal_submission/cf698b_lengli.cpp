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

    int root=-1;

    for(int i=1;i<=n;i++) if(a[i]==i) root=i;

    int res=0;

    for(int i=1;i<=n;i++){
        int l=i,r=a[i];
        if(dsu.same(l,r)){
            if(root!=-1) {
                if(a[i]!=root) res++;
                dsu.merge(i,root),a[i]=root;
            }else{
                root=i;
                if(a[i]!=root) res++;
                a[i]=root;
            }
        }else dsu.merge(l,r);
    }

    std::cout<<res<<"\n";
    for(int i=1;i<=n;i++) std::cout<<a[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
