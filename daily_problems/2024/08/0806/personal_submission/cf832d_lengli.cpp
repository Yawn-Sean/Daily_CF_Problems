/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

struct HLD{
    int n,cnt;
    std::vector<int> sz,dep,top,son,fa,in,out,seq;
    std::vector<std::vector<int>> g;
    void init(int nn,std::vector<std::vector<int>> &eg,int root){
        n=nn;cnt=0;g=eg;
        sz.clear(),dep.clear();
        top.clear(),seq.clear();
        son.clear(),fa.clear();
        in.clear(),out.clear();
        sz.resize(n+1),dep.resize(n+1);
        top.resize(n+1),seq.resize(n+1);
        son.resize(n+1),fa.resize(n+1);
        in.resize(n+1),out.resize(n+1);
        
        dep[root] = 1;
        top[root] = root;
        dfs1(root);
        dfs2(root);
    };
    void dfs1(int u){
        if (fa[u]) g[u].erase(find(g[u].begin(),g[u].end(),fa[u]));
        sz[u]=1;
        for(auto &j:g[u]){
            fa[j]=u;
            dep[j]=dep[u]+1;
            dfs1(j);
            sz[u]+=sz[j];
            if (sz[j]>sz[g[u][0]])
                std::swap(j,g[u][0]);
        }
    }
    void dfs2(int u){
        in[u]=++cnt;
        seq[in[u]]=u;
        //do something
        for (auto j : g[u]){
            top[j]=(j == g[u][0] ? top[u] : j);
            dfs2(j);
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
    std::vector<std::array<int,2>> get_path(int u,int v,int is_edge=0){
        std::vector<std::array<int,2>> res;
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]]) std::swap(u,v);
            res.push_back({in[top[u]],in[u]});
            u=fa[top[u]];
        }
        if(dep[u]>dep[v]) std::swap(u,v);
        if(is_edge and u==v) return res;
        res.push_back({in[u]+is_edge,in[v]});
        return res;
    }
    std::vector<std::array<int,2>> get_tree(int u,int is_edge=0){
    	if(is_edge and in[u]==out[u]) assert(0);
        return {{in[u]+is_edge,out[u]}};
    }
}hld;

const int N=100010;

struct Tag{//lazy tag
    int add=0;
    Tag(int a=0):add(a) {};
    void apply(Tag t){
        add=(add+t.add);
    };
};

struct Info{//information
    int l,r;
    int sum;
    Info() {};
    void apply(Tag t){
        sum=sum+(r-l+1)*t.add;
    };
    friend Info operator + (const Info &a,const Info &b){
        Info res;
        res.l=a.l,res.r=b.r;
        res.sum=a.sum+b.sum;
        return res;
    };
};

struct Segment_tree{
    Info info[N*4];
    Tag tag[N*4];
    
    void pushup(int u){
        info[u]=info[u<<1]+info[u<<1|1];
    }
    
    void apply(int u,const Tag &t){
        info[u].apply(t);
        tag[u].apply(t);
    }
    
    void pushdown(int u){
        apply(u<<1,tag[u]);
        apply(u<<1|1,tag[u]);
        tag[u]=Tag();
    }
    
    void build(int u,int l,int r){
        tag[u]=Tag();
        info[u].l=l,info[u].r=r;
        if(l==r) {
            info[u].l=l,info[u].r=r;
            info[u].sum=0;
        }else{
            int mid=(l+r)>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
    }
    
    void modify(int u,int l,int r,int pl,int pr,const Tag &t){
        if(l>=pl and r<=pr) {
            apply(u,t);
            return;
        }
        pushdown(u);
        int mid=(l+r)>>1;
        if(pl<=mid) modify(u<<1,l,mid,pl,pr,t);
        if(pr>mid) modify(u<<1|1,mid+1,r,pl,pr,t);
        pushup(u);
    }
    
    Info query(int u,int l,int r,int pl,int pr){
        if(l>=pl and r<=pr) return info[u];
        pushdown(u);
        int mid=(l+r)>>1;
        if(pl>mid) return query(u<<1|1,mid+1,r,pl,pr);
        else if(pr<=mid) return query(u<<1,l,mid,pl,pr);
        else return query(u<<1,l,mid,pl,pr)+query(u<<1|1,mid+1,r,pl,pr);
    }
}tr;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> eg(n+2);
    for(int i=2;i<=n;i++){
        int p;
        std::cin>>p;
        eg[p].pb(i);
        eg[i].pb(p);
    }
    hld.init(n,eg,1);
    tr.build(1,1,n);
    for(int i=1;i<=m;i++){
        std::vector<int> a(3);
        for(auto &x:a) std::cin>>x;
        auto dis=[&](int a,int b,int c,int d){
            int s=std::min(b,d)-std::max(a,c)+1;
            int res=std::max(0,s);
            return res;
        };
        auto get=[&](int u,int x,int y){
            auto p=hld.get_path(x,u);
            auto q=hld.get_path(y,u);
            int res=0;
            for(int i=0;i<p.size();i++){
                for(int j=0;j<q.size();j++){
                    res+=dis(p[i][0],p[i][1],q[j][0],q[j][1]);
                }
            }
            return res;
        };
        int res=0;
        res=std::max(res,get(a[0],a[1],a[2]));
        res=std::max(res,get(a[1],a[0],a[2]));
        res=std::max(res,get(a[2],a[1],a[0]));
        std::cout<<res<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
