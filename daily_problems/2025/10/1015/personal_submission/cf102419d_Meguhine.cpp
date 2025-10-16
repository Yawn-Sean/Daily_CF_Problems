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

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	vector<vector<int>>e(n+1);
	for(int i=1,u,v;i<=m;++i){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	vector<int>col(n+1);
	auto dfs=[&](auto&& self,int u)->bool{
		for(auto& v:e[u]){
			if(a[u]!=a[v]) continue;
			if(a[u]==a[v]){
				if(col[v]){
					if(col[u]==col[v]) return 0;
				}
				else{
					col[v]=-col[u];
					if(!self(self,v)) return 0;
				}
			}
		}
		return 1;
	};
	for(int i=1;i<=n;++i){
		if(!col[i]){
			col[i]=1;
			if(!dfs(dfs,i)){
				cout<<"-1";
				exit(0);
			}
		}
	}
	vector<int>b,pt;
	for(int u=1;u<=n;++u) if(col[u]==-1){
		pt.push_back(u);
		for(auto& v:e[u]){
			b.emplace_back(a[u]^a[v]);
		}
	}
	sort(all(b));
	b.erase(unique(all(b)),b.end());
	dbg(pt); dbg(b);
	for(int x=0;;++x){
		if(x==b.size() || b[x]!=x){
			cout<<pt.size()<<' '<<x<<'\n';
			for(auto& y:pt) cout<<y<<' ';
			exit(0);
		}
	}
	return 0;
}
