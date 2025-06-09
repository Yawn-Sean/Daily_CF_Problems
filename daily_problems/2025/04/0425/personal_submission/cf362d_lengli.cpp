/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define int long long

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
        sz[x] += sz[y];
        p[y] = x;
        return 1;
    }
    int size(int x){
        return sz[find(x)];
    }
};

void solve(){
    int n,m,p,q;
    std::cin>>n>>m>>p>>q;
    int cnt=n;

    std::vector<int> u(m+2),v(m+2),w(m+2);

    for(int i=1;i<=m;i++){
        std::cin>>u[i]>>v[i]>>w[i];
    }
    
    DSU dsu(n+2);

    for(int i=1;i<=m;i++){
        if(!dsu.same(u[i],v[i])){
            cnt--;
            dsu.merge(u[i],v[i]);
        }
        dsu.sz[dsu.find(u[i])]+=w[i];
    }
    if(cnt<q or cnt>p+q or (q==n and p>0)){
        std::cout<<"NO"<<"\n";
        return;
    }

    std::priority_queue<std::array<i64,2>> que;
    for(int i=1;i<=n;i++){
        if(dsu.find(i)==i){
            que.push({-dsu.size(i),i});
        }
    }
    std::cout<<"YES"<<"\n";
    while(que.size()>1 and cnt>q){
        p--;cnt--;
        auto l=dsu.find(que.top()[1]);
        que.pop();
        auto r=dsu.find(que.top()[1]);
        que.pop();
        dsu.p[r]=l;
        dsu.sz[l]=(dsu.sz[l]+dsu.sz[r])+std::min(1ll*1000000000,1ll+dsu.sz[l]+dsu.sz[r]);
        std::cout<<l<<" "<<r<<"\n";
        que.push({-dsu.sz[l],l});
    }
    for(int i=1;i<=n and p;i++){
        if(dsu.find(i)!=i){
            while(p){
                std::cout<<i<<" "<<dsu.find(i)<<"\n";
                p--;
            }
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
