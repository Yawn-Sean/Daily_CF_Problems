#ifdef __FUCK_GCC
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("inline","fast-math","unroll-loops")
#endif
#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<local/dbg.h>
#else
#define dbg(...) 42
#endif

using LL=long long;
#define ai(x) using ai##x=array<int,x>;
ai(2);ai(3);ai(4);ai(5);ai(6);ai(7);ai(8);ai(9);ai(10);ai(26);
#undef ai

#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
template<typename T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<typename T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<typename T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

void build_tree(string& s,auto&& e,auto&& id){
	const int n=(int)(s.size())/2;
	s.insert(0,"("); s+=")";
	e.assign(n+1,{});
	id.assign(s.size(),-1);
	int tot=0;
	stack<int>stk;
	for(int i=0;i<(int)s.size();++i){
		if(s[i]=='('){
			if(stk.size()){
				e[stk.top()].emplace_back(tot);
			}
			stk.push(tot);
			id[i]=tot++;
		}
		else{
			id[i]=stk.top();
			stk.pop();
		}
	}
}

struct HLD{
	vector<int>dep,fa,siz,son;
	vector<int>dfn,out,top;
#ifdef HLD_SGT
	vector<int>sgt_init;
	SGT sgt;
#endif
	int root;
	HLD(){}
	HLD(const auto& e,int n,int rt=1){init(e,n,rt);}
	void init(const auto& e,int n,int rt=1){
		root=rt;
		dep.resize(n+1),fa.resize(n+1),
		siz.resize(n+1),son.assign(n+1,-1);
		auto dfs1=[&](auto&& self,int u,int pre)->void{
			dep[u]=dep[pre]+1,fa[u]=pre,siz[u]=1;
			for(auto v:e[u]){
				if(v==pre) continue;
				self(self,v,u);
				siz[u]+=siz[v];
				if(son[u]==-1 || siz[v]>siz[son[u]]) son[u]=v;
			}
		};
		dfs1(dfs1,root,-1);
		dfn.resize(n+1),out.resize(n+2),top.resize(n+1);
		int timStamp=0;
		auto dfs2=[&](auto&& self,int u,int t)->void{
			dfn[u]=out[u]=++timStamp,top[u]=t;
			if(son[u]==-1) return;
			self(self,son[u],t);
			for(auto v:e[u]){
				if(v==fa[u] || v==son[u]) continue;
				self(self,v,v);
			}
			out[u]=timStamp;
		};
		dfs2(dfs2,root,root);
	}
	int LCA(int u,int v){
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			u=fa[top[u]];
		}
		return dep[u]<dep[v]?u:v;
	};
	int dist(int u,int v){ //edges
		return dep[u]+dep[v]-dep[LCA(u,v)]*2;
	}
};

template<typename T> // T is int or LL
struct Fenwick{
	int n,LOG;
	vector<T>c;
	inline int lowbit(const int& x){
		return x&(-x);
	}
	Fenwick(int n_){
		init(n_);
	}
	void init(int n_){
		c.assign(n=n_,T(0));
		LOG=__lg(n)+1;
	}
	void add(int i,T x){
		for(;i<n;i+=lowbit(i)) c[i]+=x;
	}
	T query(int i){
		T res=0;
		for(;i;i-=lowbit(i)) res+=c[i];
		return res;
	}
	int kth(T k){ // min p that sum(1,p)>=k
		int ans=0; T cnt=0;
		for(int i=LOG;~i;--i) {
			int nxt=ans+(1<<i);
			if(nxt<n && cnt+c[nxt]<k){
				cnt+=c[nxt];
				ans=nxt;
			}
		}
		return ans+1;
	}
};

void solve(){
	int n,Q; string s;
	cin>>n>>Q>>s;
	vector<vector<int>>e;
	vector<int>id;
	build_tree(s,e,id);
	vector<int>a(n*2+2);
	for(int i=1;i<=n*2;++i) cin>>a[i];
	HLD hld(e,n,0);
	Fenwick<LL>fen(n+2);
	for(int i=1;i<=n*2;++i){
		if(s[i]==')') continue;
		const int u=id[i];
		fen.add(hld.dfn[hld.fa[u]],-a[i]);
		fen.add(hld.dfn[u],a[i]);
	}
	for(int op;Q--;){
		cin>>op;
		if(op==1){
			int u,v,x;
			cin>>u>>u>>v>>v>>x;
			int l=hld.LCA(id[u],id[v]);
			fen.add(hld.dfn[l],x);
		}
		else{
			int u;
			cin>>u>>u;
			u=id[u];
			LL x=fen.query(hld.out[u])-fen.query(hld.dfn[u]-1);
			cout<<x<<'\n';
		}
	}
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
