/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=4e18;

struct DSU{
    std::vector<int> p,sz;
    DSU(){};
    DSU(int n){
        p.resize(n+2);sz.resize(n+2);
        for(int i=0;i<n+2;i++) p[i]=i,sz[i]=1;
    };
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    void merge(int u,int v){
        u=find(u),v=find(v);
        if(u==v) return;
        p[u]=v;
        sz[v]+=sz[u];
    }
};

void solve(){
    int n,m,G,S;
    std::cin>>n>>m>>G>>S;
    std::vector<std::array<int,4>> edge(m);
    for(auto &[u,v,g,s]:edge) std::cin>>u>>v>>g>>s;
    std::sort(all(edge),[&](auto l,auto r){
        return l[2]<r[2];
    });
 
    i64 mxg=0,mxs=0;
    i64 res=inf;
    std::vector<std::array<int,4>> q,tr;
    for(auto x:edge){
        q.pb(x);
        std::sort(all(q),[&](auto l,auto r){
            return l[3]<r[3];
        });
        DSU dsu(n);
        mxg=0,mxs=0;
        for(auto [u,v,g,s]:q){
            if(dsu.find(u)!=dsu.find(v)){
                dsu.merge(u,v);
                tr.pb({u,v,g,s});
                mxg=std::max(mxg,1ll*g);
                mxs=std::max(mxs,1ll*s);
            }
        }
        q.swap(tr);
        if(dsu.sz[dsu.find(1)]==n){
            res=std::min(res,mxg*G+mxs*S);
        }
        tr.clear();
    } 
    if(res==inf) std::cout<<"-1"<<"\n";
    else std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
