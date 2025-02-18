/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

template <unsigned M_> struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0U) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
  ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1U); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0U; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
  template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
  template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
  template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  bool operator<(const ModInt &a) const { return (x < a.x); }
  bool operator>(const ModInt &a) const { return (x > a.x); }
  bool operator<=(const ModInt &a) const { return (x <= a.x); }
  bool operator>=(const ModInt &a) const { return (x >= a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
  friend std::istream &operator>>(std::istream &is, ModInt &a) {int v;is >> v;a = ModInt(v);return is;}
};
constexpr unsigned MO = 1000000007;
using Mint = ModInt<MO>;

const int N=200010;

struct E_DCC{
	int n,cnt,cnt_edge;
	int dfn[N], low[N];
	std::vector<std::pair<int, int>> e[N];
	std::vector<std::vector<int>> ans;
	std::stack<int> st;
	std::vector<std::array<int,2>> bridge;
    int is_bridge[N];
	
	void init(int nn){
		n=nn,cnt_edge=cnt=0;
		st=std::stack<int>();
		ans.clear();bridge.clear();
		for(int i=1;i<=n;i++) {
			e[i].clear();
			dfn[i]=low[i]=0;
			is_bridge[i]=0;
		}
	}
	
	void add(int u,int v){
		cnt_edge++;
		e[u].push_back(std::make_pair(v, cnt_edge<<1));
		e[v].push_back(std::make_pair(u, cnt_edge<<1|1));
	}
	
	void dfs(int x, int las){
		low[x] = dfn[x] = ++cnt;
		st.push(x);
		for (auto i: e[x]){
			if (i.second == (las ^ 1)) continue;
			if (!dfn[i.first]){
				dfs(i.first, i.second);
				low[x] = std::min(low[x], low[i.first]);
				if(low[i.first]>dfn[x]){
                    bridge.push_back({x,i.first});
                    is_bridge[x]=1;
                    is_bridge[i.first]=1;
                }
			}else low[x] = std::min(low[x], dfn[i.first]);
		}
		if (dfn[x] == low[x]){
			std::vector<int> vec;
			vec.push_back(x);
			while (st.top() != x){
				vec.push_back(st.top());
				st.pop();
			}
			st.pop();
			ans.push_back(vec);
		}
	}
	
	void tarjan(){
		for(int i=1;i<=n;i++) 
			if(!dfn[i]) dfs(i,0);
	}
}tj;

int w[N],a[N];

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
        a[in[u]]=w[u];
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

struct Info{//information
    int l,r;
    int v;
    Info() {};
    friend Info operator + (const Info &a,const Info &b){
        Info res;
        res.l=a.l,res.r=b.r;
        res.v=a.v+b.v;
        return res;
    };
};

struct Segment_tree{
    Info info[N*4];
    
    void pushup(int u){
        info[u]=info[u<<1]+info[u<<1|1];
    }
    
    void build(int u,int l,int r){
        info[u].l=l,info[u].r=r;
        if(l==r) {
            info[u].v=a[l];
        }else{
            int mid=(l+r)>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
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
    int n,m;
    std::cin>>n>>m;
    std::vector<std::array<int,2>> edge(m);
    tj.init(n+1);
    for(auto &[u,v]:edge){
        std::cin>>u>>v;
        tj.add(u,v);
    }
    tj.tarjan();
    std::vector<int> col(n+2);
    int cnt=tj.ans.size();
    for(int i=1;i<=cnt;i++){
        for(auto x:tj.ans[i-1]) col[x]=i;
        w[i]=(tj.ans[i-1].size()>=2);
    }
    std::vector<std::vector<int>> eg(cnt+1);
    for(auto [l,r]:edge){
        if(col[l]==col[r]) continue;
        eg[col[l]].pb(col[r]);
        eg[col[r]].pb(col[l]);
    }
    hld.init(cnt,eg,1);
    tr.build(1,1,cnt);
    int q;
    std::cin>>q;
    while(q--){
        int u,v;
        std::cin>>u>>v;
        u=col[u],v=col[v];
        auto qr=hld.get_path(u,v);
        int k=0;
        for(auto [l,r]:qr) k+=tr.query(1,1,cnt,l,r).v;
        std::cout<<Mint(2).pow(k)<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
