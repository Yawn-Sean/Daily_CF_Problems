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

using JYC=array<vector<ai2>,2>;
constexpr int inf=2e9;

void solve(){
	int n; cin>>n;
	vector<JYC>a;
	vector<int>wb;
	{
		map<int,JYC>mp;
		int m; cin>>m;
		wb.reserve(m*2);
		for(int u,v,t;m--;){
			cin>>u>>v>>t;
			mp[t][0].push_back({u,v});
			mp[t][1].push_back({v,u});
		}
		auto view=mp|views::values;
		a.assign(all(view));
	}
	vector<int>dp(n+1,inf),ndp(n+1,inf);
	dp[1]=0;
	for(auto& vec:a){
		auto work=[&]<bool $>(auto&& e)->void {
			for(auto& [u,v]:e){
				wb.emplace_back(v);
				if constexpr ($) updmn(ndp[v],dp[u]+1);
				else updmn(ndp[v],dp[u]);
			}
		};
		wb.clear();
		work.operator()<0>(vec[0]);
		work.operator()<1>(vec[1]);
		for(auto u:wb){
			updmn(dp[u],ndp[u]);
			ndp[u]=inf;
		}
	}
	if(dp[n]==inf) dp[n]=-1;
	cout<<dp[n]<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
