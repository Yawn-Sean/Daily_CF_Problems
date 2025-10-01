#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<PII>> g(n);
	for(int i = 0 ; i < m ; i ++){
		int u, v, c;
		cin >> u >> v >> c;
		u--;
		v--;
		g[u].emplace_back(v, c);
		g[v].emplace_back(u, c);
	}

	vector<int> ans, vis(n), dis(n, 1e18);
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({0, 0});
	dis[0] = 0;
	while(!pq.empty()){
		auto [_, u] = pq.top(); pq.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(auto [v , w] : g[u]){
			if(!vis[v] && dis[v] >= dis[u] + w){
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
	vis.assign(n, 0);
	queue<int> q;
	q.push(n-1);
	while(!q.empty()){
		auto u = q.front(); q.pop();
		if(vis[u])continue;
		vis[u] = 1;
		for(auto [v, w] : g[u]){
			if(!vis[v]){
				q.push(v);
				ans.emplace_back(w);
			}
		}
	}
	sort(ans.begin(), ans.end());
	int res = 0;
	//for(int i = 0; i < n; i ++)cout << dis[i] <<" ";
	for(int i = 0; i < min(k, (int)ans.size()); i ++)res += ans[i];
	cout << min(res, dis[n-1]) << '\n';
}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	//cin >> t;
	t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}
