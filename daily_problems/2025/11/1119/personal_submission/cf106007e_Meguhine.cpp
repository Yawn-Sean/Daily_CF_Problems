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

void solve(){
	int n,Q; string s;
	cin>>n>>Q>>s;
	vector<vector<int>>e(n+1);
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	vector<int>qry(Q);
	for(auto& x:qry) cin>>x;
	const int root=qry[0];
	vector<int>fa(n+1);
	auto dfs=[&](auto&& self,int u,int p)->void{
		fa[u]=p;
		for(auto& v:e[u]){
			if(v==p) continue;
			self(self,v,u);
		}
	};
	dfs(dfs,root,0);
	dbg(root,fa);
	vector<int>col(n+1); // 0:white, 1:gray, 2:black
	col[root]=2;
	int white=n-1,gray=0;
	auto work=[&](int u)->void{
		if(col[u]==2) return;
		if(!col[u]) --white;
		else --gray;
		col[u]=2;
		while(1){
			u=fa[u];
			if(!u || col[u]) break;
			col[u]=1;
			--white,++gray;
		}
	};
	for(int u=1;u<=n;++u){
		if(s[u-1]=='0'){
			work(u);
		}
	}
	for(auto& u:qry){
		work(u);
		dbg(white,gray);
		LL ans=1ll*white*(white+1)/2+1ll*white*gray;
		cout<<ans<<'\n';
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
