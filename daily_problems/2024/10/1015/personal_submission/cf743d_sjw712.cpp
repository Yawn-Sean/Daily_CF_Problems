const int INF = 1e18;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >> a[i];
	vector<vector<int>> adj(n + 1);
	vector<int> dp(n + 1), cnt(n + 1), sum(n + 1), p(n + 1);
	for(int i = 1; i <= n - 1; i ++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = -INF;
	auto dfs1 = [&](auto self, int u, int fa)->void{
		p[u] = fa;
		sum[u] = a[u];
		for(auto v : adj[u]){
			if(v == fa) continue;
			cnt[u] ++;
			self(self, v, u);
			sum[u] += sum[v];
		}
		dp[u] = sum[u];
		for(auto v : adj[u]){
			if(v == fa) continue;
			dp[u] = max(dp[u], dp[v]);
		}
	};
	dfs1(dfs1, 1, 0);
	for(int u = 1; u <= n; u ++){
		if(cnt[u] < 2) continue;
		int mx1 = -INF, mx2 = -INF;
		for(auto v : adj[u]){
			if(v == p[u]) continue;
			if(dp[v] >= mx1){
				mx2 = mx1;
				mx1 = dp[v];
			}
			else if(dp[v] >= mx2){
				mx2 = dp[v];
			}
		}
		ans = max(ans, mx1 + mx2);
	}
	if(ans == -INF) cout << "Impossible" << '\n';
	else cout << ans << '\n';
}
