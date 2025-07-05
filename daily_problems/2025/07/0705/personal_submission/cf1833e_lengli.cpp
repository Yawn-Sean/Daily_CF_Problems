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
    std::cin>>n;
    std::vector<int> a(n+2),rd(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    int mx=0,mi=0;

    std::set<std::array<int,2>> q;

    DSU dsu(n+2);
    for(int i=1;i<=n;i++){
        int l=i,r=a[i];
        if(l>r) std::swap(l,r);
        if(q.count({l,r})) continue;
        q.insert({l,r});
        dsu.merge(l,r);
        rd[l]++,rd[r]++;
    }

    int cnt=0;

    for(int i=1;i<=n;i++){
        if(dsu.find(i)==i){
            mx++;
        }
        cnt+=rd[i]==1;
    }

    std::cout<<std::min(mx,mx-cnt/2+1)<<" "<<mx<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
