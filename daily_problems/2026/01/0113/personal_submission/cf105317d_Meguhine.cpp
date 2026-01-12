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
template<class T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<class T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<class T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

constexpr array<int,19>prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
consteval auto init(){
	array<int,71>id;
	fill(all(id),-1);
	for(int i=0;i<19;++i){
		id[prime[i]]=i;
	}
	array<int,71>mask;
	mask[0]=0;
	for(int X=1;X<=70;++X){
		int x=X,s=0;
		for(int i=0;i<prime.size() && prime[i]*prime[i]<=x;++i){
			if(x%prime[i]) continue;
			bool f=0;
			while(x%prime[i]==0){
				x/=prime[i];
				f^=1;
			}
			if(f) s|=(1<<i);
		}
		if(x!=1) s|=(1<<id[x]);
		mask[X]=s;
	}
	return make_tuple(id,mask);
}
constexpr auto init_result=init();
constexpr auto id=get<0>(init_result);
constexpr auto mask=get<1>(init_result);

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	vector<int>a(n+1);
	for(int i=1,x;i<=n;++i){
		cin>>x;
		a[i]=mask[x];
	}
	vector<vector<int>>e(n+1);
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	auto sum=a;
	vector<int>dep(n+1),fa(n+1),siz(n+1),son(n+1,-1);
	auto dfs1=[&](auto&& self,int u,int pre)->void {
		if(pre!=-1){
			dep[u]=dep[pre]+1;
			sum[u]^=sum[pre];
		}
		fa[u]=pre,siz[u]=1;
		for(auto v:e[u]){
			if(v==pre) continue;
			self(self,v,u);
			siz[u]+=siz[v];
			if(son[u]==-1 || siz[v]>siz[son[u]]) son[u]=v;
		}
	};
	dfs1(dfs1,1,-1);
	vector<int>dfn(n+1),dfn_inv(n+2),top(n+1);
	int timStamp=0;
	auto dfs2=[&](auto&& self,int u,int t)->void {
		dfn[u]=++timStamp,dfn_inv[timStamp]=u,top[u]=t;
		if(son[u]==-1) return;
		self(self,son[u],t);
		for(auto v:e[u]){
			if(v==fa[u] || v==son[u]) continue;
			self(self,v,v);
		}
	};
	dfs2(dfs2,1,1);
	auto LCA=[&](int u,int v)->int {
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			u=fa[top[u]];
		}
		return dep[u]<dep[v]?u:v;
	};
	int Q; cin>>Q;
	for(int u,v;Q--;){
		cin>>u>>v;
		int s=sum[u]^sum[v]^a[LCA(u,v)];
		cout<<(!!s)<<'\n';
	}
	return 0;
}
