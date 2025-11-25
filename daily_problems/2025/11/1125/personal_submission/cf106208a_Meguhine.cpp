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

struct DSU{
	vector<int>fa,siz;
	DSU(){}
	DSU(int n){
		init(n);
	}
	void init(int n){
		fa.resize(n);
		iota(fa.begin(),fa.end(),0);
		siz.assign(n,1);
	}
	int get(int x){
		while(x!=fa[x]){
			x=fa[x]=fa[fa[x]];
		}
		return x;
	}
	bool same(int x,int y){
		return get(x)==get(y);
	}
	bool merge(int x,int y){
		x=get(x),y=get(y);
		if(x==y) return 0;
		if(siz[y]>siz[x]) swap(x,y);
		siz[x]+=siz[y],fa[y]=x;
		return 1;
	}
	int size(int x){
		return siz[get(x)];
	}
};

#define FAIL {cout<<"NO";exit(0);}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m; cin>>n>>m;
	vector<ai3>edge(m),ck;
	for(auto& [w,u,v]:edge) cin>>u>>v>>w;
	sort(all(edge));
	DSU dsu(n+1);
	vector<vector<ai2>>e(n+1);
	for(auto& [w,u,v]:edge){
		if(dsu.merge(u,v)){
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
		else ck.push_back({w,u,v});
	}
	if(dsu.size(1)!=n) FAIL;
	constexpr int root=1;
	vector<int>dep(n+1),fa(n+1),siz(n+1),son(n+1);
	vector<LL>dep_true(n+1);
	auto dfs1=[&](auto&& self,int u,int pre)->void{
		dep[u]=dep[pre]+1,fa[u]=pre,siz[u]=1;
		for(auto [v,w]:e[u]){
			if(v==pre) continue;
			dep_true[v]=dep_true[u]+w;
			self(self,v,u);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]]) son[u]=v;
		}
	};
	dfs1(dfs1,root,0);
	vector<int>dfn(n+1),dfn_inv(n+1),top(n+1);
	int timStamp=0;
	auto dfs2=[&](auto&& self,int u,int t)->void{
		dfn[u]=++timStamp,dfn_inv[timStamp]=u,top[u]=t;
		if(!son[u]) return;
		self(self,son[u],t);
		for(auto [v,_]:e[u]){
			if(v==fa[u] || v==son[u]) continue;
			self(self,v,v);
		}
	};
	dfs2(dfs2,root,root);
	auto LCA=[&](int u,int v)->int{
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			u=fa[top[u]];
		}
		return dep[u]<dep[v]?u:v;
	};
#ifdef LOCAL
	for(int u=1;u<=n;++u){
		dbg(u,fa[u],dep_true[u]);
	}
#endif
	for(auto& [w,u,v]:ck){
		const LL d=dep_true[u]+dep_true[v]-dep_true[LCA(u,v)]*2;
		dbg(u,v,w,d);
		if(w<d) FAIL;
	}
	cout<<"YES";
	return 0;
}
