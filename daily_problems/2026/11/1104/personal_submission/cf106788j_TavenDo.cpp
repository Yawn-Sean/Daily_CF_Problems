#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define fi first 
#define se second 
using LL=long long;using ll=long long;
using PLL=pair<LL,LL>;
const LL inf = 1e18;

//枚举第k+1个边的大小为p
//每个小于p的边都变为p最后整体减小k*p，如果一个数字少减了，说明提升至该数字更优

void solve() {
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<PLL>>adj(n);
	vector<LL>ms(m);
	for(int i=0;i<m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		ms.push_back(w);
	}
	LL ans=inf;
	for(auto cm:ms){
		vector<LL>dist(n,inf);
		dist[0] = 0;
        priority_queue<PLL,vector<PLL>, greater<PLL>> pq;
        pq.push(make_pair(0LL,0LL));
        while (!pq.empty()) {
			auto [d,u]=pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& nxt:adj[u]) {
                LL v = nxt.fi;
                ll w = max(nxt.se,cm);
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v ));
                }
            }
        }
		ans=min(ans,dist[n-1]-cm*k);
	}
	cout<<max(ans,0LL)<<endl;
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