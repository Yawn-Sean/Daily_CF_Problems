#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;
using PLL=pair<LL,LL>;
const LL inf = 4e18;
//由于如果路径过多 一定出现了环 所以dp只需要记录n*m的大小的dp
struct info{
	LL w,v,d;
	bool operator>(const info &o)const {
		return w>o.w;
	}
};
void solve() {
	int n,m,t;
	cin>>n>>m>>t;
	vector<vector<PLL>>adj(n+1);
	for(int i=1;i<=m;++i){
		LL u,v,x;
		cin>>u>>v>>x;
		adj[u].push_back(make_pair(v,x));
		adj[v].push_back(make_pair(u,x));
	}
	vector<vector<LL>>dp(n+1,vector<LL>(min(n,m)+1,inf));  //dp[x][y]  到达x且焦虑为y的最小代价
	priority_queue<info,vector<info>,greater<info>>pq;
	pq.push({0,1,0});
	dp[1][0]=0;
	while(!pq.empty()){
		auto [cw,cv,cd]=pq.top();
		pq.pop();
		if(cw>dp[cv][cd]){
			continue;
		}
		for(auto &[k,x]:adj[cv]){
			LL nd=cd;
			if(x>0){
				++nd;
			}
			if(nd>min(n,m)){
				continue;
			}
			LL nw=cw+cd*x;
			if(nw<dp[k][nd]){
				dp[k][nd]=nw;
				pq.push({nw,k,nd});
			}
		}
	}
	LL mnn=inf;
	for(auto u:dp[t]){
		mnn=min(mnn,u);
	}
	if(mnn==inf){
		cout<<-1<<endl;
	}else{
		cout<<mnn<<endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}
