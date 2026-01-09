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

struct Node{
	int u,d;
	friend bool operator <(const Node& x,const Node& y){
		return x.d>y.d;
	}
};

constexpr int inf=2e9;
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m; cin>>n>>m;
	auto dij=[&](auto&& e,auto&& dp)->void {
		priority_queue<Node>q;
		q.push({1,dp[1]=0});
		while(q.size()){
			auto [u,d]=q.top();
			q.pop();
			for(auto [v,w]:e[u]){
				const int nd=max(d,w);
				if(updmn(dp[v],nd)){
					q.push({v,nd});
				}
			}
		}
	};
	vector<vector<ai2>>e(n+1),e_inv(n+1);
	for(int i=0,u,v,w;i<m;++i){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e_inv[v].push_back({u,w});
	}
	vector<int>dp(n+1,inf),dp_inv(n+1,inf);
	dij(e,dp);
	dij(e_inv,dp_inv);
	for(int u=2;u<=n;++u){
		if(dp[u]<dp_inv[u]){
			cout<<"NO";
			exit(0);
		}
	}
	cout<<"YES";
	return 0;
}
