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

#define FAIL {cout<<"NO\n";return;}
void solve(){
	int n; cin>>n;
	vector<vector<int>>e(n+1);
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	vector<bool>tag(n+1);
	for(int u=1;u<=n;++u){
		if(e[u].size()>=4) FAIL;
		if(e[u].size()==3) tag[u]=1;
	}
	auto dfs=[&](auto&& self,int u,int fa)->int {
		// -1: FAIL
		// 0: no tag
		// 1: an edge
		// 2: a link
		ai3 r{};
		for(auto v:e[u]){
			if(v==fa) continue;
			const int t=self(self,v,u);
			if(t==-1) return -1;
			++r[t];
		}
		if(r[1]>=3) return -1;
		if(r[2]>=2) return -1;
		if(r[1] && r[2]) return -1;
		if(tag[u]){
			if(r[2]) return -1;
			if(r[1]>=2) return 2;
			return 1;
		}
		else{
			if(r[1]==1) return 1;
			if(r[1]==2) return 2;
			if(r[2]) return 2;
			return 0;
		}
	};
	if(dfs(dfs,1,0)==-1) FAIL;
	cout<<"YES\n";
}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
