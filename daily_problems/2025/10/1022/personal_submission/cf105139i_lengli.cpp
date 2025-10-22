/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=200010;

vector<int> eg[N];

struct HLD{
    int n,cnt;
    vector<int> sz,dep,top,son,fa,in,out,seq;
    void init(int nn){
        n=nn;cnt=0;
        sz.clear(),dep.clear();
        top.clear(),seq.clear();
        son.clear(),fa.clear();
        in.clear(),out.clear();
        sz.resize(n+1),dep.resize(n+1);
        top.resize(n+1),seq.resize(n+1);
        son.resize(n+1),fa.resize(n+1);
        in.resize(n+1),out.resize(n+1);
    };

    void dfs1(int u,int f,int d){
        dep[u]=d;sz[u]=1;fa[u]=f;
        for(auto x:eg[u]){
            if(x==f) continue;
            dfs1(x,u,d+1);
            sz[u]+=sz[x];
            if(sz[x]>sz[son[u]]) son[u]=x;
        }
    }

    void dfs2(int u,int f){
        in[u]=++cnt,seq[in[u]]=u;
        top[u]=f;
        if(!son[u]) {
            out[u]=cnt;
            return;
        }
        dfs2(son[u],f);
        for(auto x:eg[u]){
            if(x==fa[u] or x==son[u]) continue;
            dfs2(x,x);
        }
        out[u]=cnt;
    }

    int lca(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]]) v=fa[top[v]];
            else u=fa[top[u]];
        }
        return dep[u]<dep[v] ? u : v;
    }

    int dist(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }

    vector<array<int,2>> get_path(int u,int v){
        vector<array<int,2>> res;
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]]) swap(u,v);
            res.push_back({in[top[u]],in[u]});
            u=fa[top[u]];
        }
        if(dep[u]>dep[v]) swap(u,v);
        res.push_back({in[u],in[v]});
        return res;
    }

    vector<array<int,2>> get_tree(int u){
        return {{in[u],out[u]}};
    }

    void build(int root){
        dfs1(root,0,1);
        dfs2(root,root);
    }
}hld;

struct DSU{
    std::vector<int> p;
    DSU(int n): p(n+2){
        std::iota(p.begin(), p.end(), 0);
    }
    void clear(int n){
        for(int i=1;i<=n;i++) p[i]=i;
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
        p[y] = x;
        return 1;
    }
};

struct Diameter{
    int x,y;
    Diameter(){};
    Diameter(int x,int y):x(x),y(y){};
    friend Diameter operator + (Diameter a,Diameter b){
        int ma=0,rx=-1,ry=-1;
        for(auto l:{a.x,a.y,b.x,b.y}){
            for(auto r:{a.x,a.y,b.x,b.y}){ 
                int d=hld.dist(l,r);
                if(d>ma){
                    ma=d;
                    rx=l,ry=r;
                }
            }
        }
        return Diameter(rx,ry);
    }
};

int n,m;

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) eg[i].clear();

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        eg[a].pb(b);
        eg[b].pb(a);
    }
    hld.init(n);
    hld.build(1);
    
    DSU tr(n);

    vector<int> ti(n+1,-1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        int c=hld.lca(a,b);
        a=tr.find(a);
        while(hld.dep[a]>=hld.dep[c]){
            ti[a]=i;
            tr.p[a]=hld.fa[a];
            a=tr.find(a);
        }
        b=tr.find(b);
        while(hld.dep[b]>=hld.dep[c]){
            ti[b]=i;
            tr.p[b]=hld.fa[b];
            b=tr.find(b);
        }
    }
    
    tr.clear(n);
    vector<vector<int>> q(m+1);
    for(int i=1;i<=n;i++){
        if(ti[i]!=-1) q[ti[i]].pb(i);
    }
    int ma=0;
    vector<Diameter> d(n+1);
    vector<bool> st(n+1,0);
    vector<int> res(m+1,0);
    for(int i=0;i<m;i++){
        for(auto x:q[i]){
            d[x]=Diameter(x,x);
            st[x]=1;
            for(auto v:eg[x]){
                if(st[v]){
                    int l=tr.find(x),r=tr.find(v);
                    if(l==r) continue;
                    tr.p[l]=r;
                    d[r]=d[x]+d[r];
                    d[x]=d[r];
                    ma=max(ma,hld.dist(d[r].x,d[r].y));
                }
            }
        }
        res[i]=max(res[i],ma);
    }

    tr.clear(n);
    for(int i=0;i<=m;i++) q[i].clear();
    for(int i=0;i<=n;i++) st[i]=0,d[i]=Diameter(-1,-1);
    ma=0;

    for(int i=1;i<=n;i++){
        if(ti[i]==-1) q[m-1].pb(i);
        else if(ti[i]>=1) q[ti[i]-1].pb(i);
    }
    for(int i=m-1;i>=0;i--){
        for(auto x:q[i]){
            d[x]=Diameter(x,x);
            st[x]=1;
            for(auto v:eg[x]){
                if(st[v]){
                    int l=tr.find(x),r=tr.find(v);
                    if(l==r) continue;
                    tr.p[l]=r;
                    d[r]=d[x]+d[r];
                    d[x]=d[r];
                    ma=max(ma,hld.dist(d[r].x,d[r].y));
                }
            }
        }
        res[i]=max(res[i],ma);
    }
    

    for(int i=0;i<m;i++) cout<<res[i]+1<<endl;
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
