void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> tree(n);
	vector<int> fa(n, -1), st(n), ed(n), wish(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		fa[v] = u;
		tree[u].emplace_back(v);
		tree[v].emplace_back(u);
	}
	for (int i = 0; i < n; i++) {
		cin >> wish[i];
		wish[i]--;
	}
	vector<int> ans;
	auto dfs = [&](auto&& dfs, int u, int p) -> bool {
		for (int v : tree[u]) {
			if (v == p) continue;
			if (wish[v] != v && wish[v] != wish[u]) {
				return false;
			}
			if (!dfs(dfs, v, u)) return false;
		}
		if (wish[u] == u) ans.emplace_back(u);
		return true;
	};	
	for (int i = 0; i < n; i++) {
		if (fa[i] == -1 && !dfs(dfs, i, -1)) {
			cout << "-1\n";
			return;
		}
	}
	cout << sz(ans) << "\n";
	for (int x : ans) {
		cout << x + 1 << "\n";
	}
}
