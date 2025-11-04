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

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m;
	cin>>n>>m;
	vector<int>h(n);
	vector<ai2>a(n);
	for(int i=0;i<n;++i){
		cin>>h[i];
		a[i]={h[i],i};
	}
	vector<vector<int>>e(n);
	for(int i=0,u,v;i<m;++i){
		cin>>u>>v;
		--u,--v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	sort(all(a));
	ai2 st{-1,-1};
	for(int i=0;i<n;++i){
		if(a[i][1]<=1){
			if(st[0]==-1) st[0]=i;
			else{
				st[1]=i;
				break;
			}
		}
	}
	dbg(st);
	auto OK=[&](int l,int r,int u)->bool{
		return a[l][0]<=h[u] && h[u]<=a[r][0];
	};
	auto FUCK=[&](int l,int r,int i,auto&& dsu)->void{
		const int& u=a[i][1];
		for(auto& v:e[u]){
			if(OK(l,r,v)){
				dsu.merge(u,v);
			}
		}
	};
	DSU base(n);
	for(int i=st[0];i<=st[1];++i){
		FUCK(st[0],st[1],i,base);
	}
	int ans=1e9;
	for(int l=st[0];a[st[1]][0]-a[l][0]<ans;){
		DSU dsu=base;
		for(int r=st[1];;){
			if(dsu.same(0,1)){
				updmn(ans,a[r][0]-a[l][0]);
				break;
			}
			if(++r<n);
			else break;
			FUCK(l,r,r,dsu);
		}
		if(~(--l));
		else break;
		FUCK(l,st[1],l,base);
	}
	cout<<ans;
	return 0;
}
