void solve(){
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	vector<int> deg(n + 1);
	for(int i = 1; i < n; i ++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u] ++, deg[v] ++;
	}
	for(int i = 1; i <= n; i ++){
		if(deg[i] > 4) return cout << "NO" << '\n', void();
	}
	vector<pii> ans(n + 1);
	vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	auto dfs = [&](auto self, int u, int fa, int dep, int x, int y, int d)->void{
		ans[u] = {x, y};
		int cnt = 0;
		for(auto v : adj[u]){
			if(v == fa) continue;
			if(cnt == d && u != 1) cnt ++;
			int nx = x + dir[cnt][0] * (1ll << (31 - dep - 1));
			int ny = y + dir[cnt][1] * (1ll << (31 - dep - 1));
			self(self, v, u, dep + 1, nx, ny, cnt ^ 1ll);
			cnt ++;
		}
	};
	dfs(dfs, 1, 0, 0, 0, 0, 0);
	cout << "YES" << '\n';
	for(int i = 1; i <= n; i ++){
		cout << ans[i].x << " " << ans[i].y << '\n';
	}
}
