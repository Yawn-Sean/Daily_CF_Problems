/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

struct HLD{
    int n,cnt;
    std::vector<int> sz,top,son,fa,in,out,seq,bk;
    std::vector<long long> len,dep;
    std::vector<std::vector<std::array<int,2>>> g;
    std::vector<int> val;
    void init(int nn,std::vector<std::vector<std::array<int,2>>> &eg,int root,std::vector<int> c){
        n=nn;cnt=0;g=eg;val=c;
        sz.clear(),dep.clear();
        top.clear(),seq.clear();
        son.clear(),fa.clear();
        in.clear(),out.clear();
        bk.clear(),len.clear();
        sz.resize(n+1),dep.resize(n+1);
        top.resize(n+1),seq.resize(n+1);
        son.resize(n+1),fa.resize(n+1);
        in.resize(n+1),out.resize(n+1);
        bk.resize(n+1),len.resize(n+1);
        len[root] = 0;
        top[root] = root;
        dfs1(root);
        dfs2(root);
    };
    void dfs1(int u){
        if (fa[u]) {
            for(auto it=g[u].begin();it!=g[u].end();it++){
                if((*it)[0]==fa[u]){
                    g[u].erase(it);
                    break;
                }
            }
        }
        sz[u]=1;
        for(auto &[j,w]:g[u]){
            fa[j]=u;
            len[j]=len[u]+w;
            dfs1(j);
            sz[u]+=sz[j];
            if (sz[j]>sz[g[u][0][0]])
                std::swap(j,g[u][0][0]);
        }
    }
    void dfs2(int u){
        in[u]=++cnt;
        seq[in[u]]=u;
        bk[in[u]]=val[u];
        dep[in[u]]=len[u];
        for (auto [j,w] : g[u]){
            top[j]=(j == g[u][0][0] ? top[u] : j);
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

struct Tag{
	long long d_add=0,v_add=0;
	Tag(int a=0,int b=0):d_add(a),v_add(b) {};
	void apply(Tag t){
		d_add+=t.d_add;
        v_add+=t.v_add;
	};
};

struct Info{//information
	int l,r;
	long long d=0,v=0;
    long long mi=0;
	Info() {};
	void apply(Tag t){
		d+=t.d_add;
        v+=t.v_add;
        mi+=t.d_add+(l==r ? t.v_add : 0);
	};
	friend Info operator + (const Info &a,const Info &b){
		Info res;
		res.l=a.l,res.r=b.r;
        res.mi=std::min(a.mi,b.mi);
		return res;
	};
};

constexpr int N=200010;

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
			info[u].d=hld.dep[l];
            info[u].v=hld.bk[l];
            info[u].mi=info[u].d+info[u].v;
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
    int n,q;
    std::cin>>n>>q;
    std::vector<std::vector<std::array<int,2>>> eg(n+1);
    std::vector<std::array<int,3>> edge(n*2);
    for(int i=1;i<=n*2-2;i++){
        auto &[u,v,w]=edge[i];
        std::cin>>u>>v>>w;
    }
    std::vector<int> c(n+1);
    for(int i=1;i<=n*2-2;i++){
        auto [u,v,w]=edge[i];
        if(i<n) eg[u].pb({v,w});
        else c[u]=w;
    }

    hld.init(n,eg,1,c);
    tr.build(1,1,n);

    for(int i=1;i<=q;i++){
        int op;
        std::cin>>op;
        if(op==1){
            int id,w;
            std::cin>>id>>w;
            if(id<n){
                int dlt=w-edge[id][2];
                for(auto [l,r]:hld.get_tree(edge[id][1])){
                    tr.modify(1,1,n,l,r,Tag(dlt,0));
                }
            }else{
                int dlt=w-edge[id][2];
                int v=edge[id][0];
                tr.modify(1,1,n,hld.in[v],hld.in[v],Tag(0,dlt));
            }
            edge[id][2]=w;
        }else{
            int u,v;
            std::cin>>u>>v;
            long long res=0;
            if(hld.in[u]<=hld.in[v] and hld.in[v]<=hld.out[u]){
                res=tr.query(1,1,n,hld.in[v],hld.in[v]).d;
                res-=tr.query(1,1,n,hld.in[u],hld.in[u]).d;
            }else{
                res=tr.query(1,1,n,hld.in[v],hld.in[v]).d;
                res+=tr.query(1,1,n,hld.in[u],hld.out[u]).mi-tr.query(1,1,n,hld.in[u],hld.in[u]).d;
                
            }
            std::cout<<res<<"\n";
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
