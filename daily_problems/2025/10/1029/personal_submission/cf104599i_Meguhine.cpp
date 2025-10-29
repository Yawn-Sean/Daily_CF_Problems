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
	int n; cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
	vector<vector<int>>e(n+1);
	for(int fa,u=2;u<=n;++u){
		cin>>fa;
		e[fa].emplace_back(u);
	}
	int ans=0;
	auto dfs=[&](auto&& self,int u)->int{
		vector<int>mx{a[u]};
		for(auto& v:e[u]){
			mx.emplace_back(self(self,v)+1);
			sort(allr(mx));
			if(mx.size()>2){
				mx.pop_back();
			}
		}
		if(mx.size()==2){
			updmx(ans,mx[0]+mx[1]);
		}
		dbg(u,mx);
		return mx[0];
	};
	dfs(dfs,1);
	cout<<ans;
	return 0;
}
