/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=100010;

int a[N],w[N];
std::vector<std::array<int,2>> edge;

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
        for(auto &[l,r]:edge){
            if(dep[l]<dep[r]) std::swap(l,r);
            w[l]=1;
        }
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
        a[in[u]]=w[u];
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

struct Info{
    int sum=0;

	Info() {};
	friend Info operator + (const Info &a,const Info &b){
		Info res;
        res.sum=a.sum+b.sum;
		return res;
	};
};

struct Segment_tree{
	Info info[N*4];
	
	void pushup(int u){
		info[u]=info[u<<1]+info[u<<1|1];
	}
	
	void build(int u,int l,int r){
		if(l==r){
			info[u].sum=a[l];
		}else{
			int mid=(l+r)>>1;
			build(u<<1,l,mid);
			build(u<<1|1,mid+1,r);
			pushup(u);
		}
	}
	
	void modify(int u,int l,int r,int pl,int pr,int t){
		if(l>=pl and r<=pr) {
			info[u].sum=t;
			return;
		}
		int mid=(l+r)>>1;
		if(pl<=mid) modify(u<<1,l,mid,pl,pr,t);
		if(pr>mid) modify(u<<1|1,mid+1,r,pl,pr,t);
		pushup(u);
	}
	
	Info query(int u,int l,int r,int pl,int pr){
		if(l>=pl and r<=pr) return info[u];
		int mid=(l+r)>>1;
		if(pl>mid) return query(u<<1|1,mid+1,r,pl,pr);
		else if(pr<=mid) return query(u<<1,l,mid,pl,pr);
		else return query(u<<1,l,mid,pl,pr)+query(u<<1|1,mid+1,r,pl,pr);
	}
}tr;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> eg(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        edge.pb({u,v});
        eg[u].pb(v);
        eg[v].pb(u);
    }
    hld.init(n,eg,1);
    tr.build(1,1,n);

    int m;
    std::cin>>m;
    while(m--){
        int op;
        std::cin>>op;
        if(op==1){
            int id;
            std::cin>>id;
            id--;
            auto [l,r]=edge[id];
            tr.modify(1,1,n,hld.in[l],hld.in[l],1);
        }else if(op==2){
            int id;
            std::cin>>id;
            id--;
            auto [l,r]=edge[id];
            tr.modify(1,1,n,hld.in[l],hld.in[l],0);
        }else{
            int l,r;
            std::cin>>l>>r;
            auto ans=hld.get_path(l,r,1);
            int sum=0,real=hld.dist(l,r);
            for(auto [x,y]:ans) sum+=tr.query(1,1,n,x,y).sum;
            int t=hld.lca(l,r);
            if(sum==real) std::cout<<sum<<"\n";
            else std::cout<<"-1"<<"\n";
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
