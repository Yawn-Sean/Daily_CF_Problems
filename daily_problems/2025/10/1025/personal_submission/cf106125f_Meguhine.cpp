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

constexpr int N=2048;
#define FAIL {cout<<"impossible";exit(0);}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m;
	cin>>n>>m;
	if(n&1) FAIL;
	const int nn=n/2;
	if(1ll*nn*(nn-1)>m) FAIL;
	vector<vector<int>>e(n+1);
	{
		vector<bitset<N>>adj(n+1);
		for(int i=0,u,v;i<m;++i){
			cin>>u>>v;
			adj[u][v]=adj[v][u]=1;
		}
		for(int i=1;i<=n;++i){
			adj[i][i]=1;
			for(int j=1;j<=n;++j){
				if(!adj[i][j]){
					e[i].emplace_back(j);
				}
			}
			dbg(i,e[i]);
		}
	}
	vector<int>col(n+1);
	vector<array<vector<int>,2>>a;
	auto dfs=[&](auto&& self,int u)->void{
		for(auto& v:e[u]){
			if(!col[v]){
				col[v]=-col[u];
				a.back()[col[v]==1].push_back(v);
				self(self,v);
			}
			else{
				if(col[u]==col[v]) FAIL;
			}
		}
	};
	for(int i=1;i<=n;++i){
		if(!col[i]){
			col[i]=1;
			a.push_back({});
			a.back()[1].push_back(i);
			dfs(dfs,i);
		}
	}
	vector dp(a.size(),vector<int>(nn+1,-1));
	for(int j=0;j<2;++j){
		const int& sz=a[0][j].size();
		if(sz<=nn) dp[0][sz]=j;
	}
	for(int i=1;i<a.size();++i){
		for(int x=0;x<=nn;++x){
			if(dp[i-1][x]==-1) continue;
			for(int j=0;j<2;++j){
				const int y=x+a[i][j].size();
				if(y<=nn){
					dp[i][y]=j;
				}
			}
		}
	}
	if(dp.back()[nn]==-1) FAIL;
	bitset<N>b;
	int x=nn;
	for(int i=a.size()-1;~i;--i){
		int j=dp[i][x];
		for(auto& u:a[i][j]) b[u]=1;
		x-=a[i][j].size();
	}
	for(int i=1;i<=n;++i){
		if(b[i]) cout<<"r\n";
		else cout<<"b\n";
	}
	return 0;
}
