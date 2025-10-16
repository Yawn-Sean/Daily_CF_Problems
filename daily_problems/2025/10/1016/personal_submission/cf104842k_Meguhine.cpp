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
	vector<vector<ai2>>e(n+1);
	for(int i=1,u,v;i<n;++i){
		cin>>u>>v;
		e[u].push_back({v,i});
		e[v].push_back({u,i});
	}
	using ovi=optional<vector<ai2>*>;
#define Self self.template operator()<_>
	auto dfs=[&]<bool _>(auto&& self,int u,int fai,
			 ovi path=nullopt)->ai2{
		int node=u,len=1;
		for(auto& [v,i]:e[u]){
			if(i==fai) continue;
			vector<ai2>tmp;
			auto [tnode,tlen]=Self(self,v,i,_?ovi(&tmp):nullopt);
			++tlen;
			if(updmx(len,tlen)){
				if constexpr(_) swap(**path,tmp);
				node=tnode,len=tlen;
			}
		}
		if constexpr(_){
			(**path).push_back({u,fai});
		}
		return ai2{node,len};
	};
#undef Self
	auto [st,$]=dfs.operator()<0>(dfs,1,0);
	vector<ai2>path;
	auto [ed,len]=dfs.operator()<1>(dfs,st,0,ovi(&path));
	dbg(st,ed,len);
	dbg(path);
	vector<int>ans(n+1);
	for(int i=0;i<len/2;++i){
		ans[path[i][0]]=path[i][1];
	}
	for(int i=len/2;i<len;++i){
		ans[path[i][0]]=path[i-1][1];
	}
	auto work=[&](auto&& self,int u,int fai)->void{
		ans[u]=fai;
		for(auto& [v,i]:e[u]){
			if(i==fai) continue;
			self(self,v,i);
		}
	};
	vector<int>in_path(n+1);
	for(auto& [u,i]:path) in_path[u]=1;
	for(auto& [u,_]:path){
		for(auto& [v,i]:e[u]){
			if(!in_path[v]){
				work(work,v,i);
			}
		}
	}
	cout<<(len-1)/2<<'\n';
	for(int i=1;i<=n;++i) cout<<ans[i]<<' ';
	return 0;
}
