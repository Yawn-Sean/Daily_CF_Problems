void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), b;
	vector<vector<int>> g(n + 1);
	vector<int> d(n + 1), dep(n + 1);
	for(int i = 1; i <= m; i ++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		d[v] ++;
	}
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	auto dfs = [&](auto self, int u, int fa)->void{
		dep[u] = dep[fa] + 1;
		for(auto v: g[u]){
			self(self, v, u);
		}
	};
	for(int i = 1; i <= n; i ++){
		if(d[i] == 0){
			dfs(dfs, i, 0);
		}
	}
	sort(b.begin(), b.end(), [&](int a, int b){
		return dep[a] > dep[b];
	});
	vector<bool> st(n + 1);
	auto dfs2 = [&](auto self, int u, int x)->bool{
		if(st[u]) return true;
		if(!st[u] && a[u] != x) return false;
		st[u] = true;
		for(auto v: g[u]){
			if(!self(self, v, x)) return false;
		}
		return true;
	};
	for(int i = 0; i < b.size(); i ++){
		if(!dfs2(dfs2, b[i], b[i])) return cout << -1 << '\n', void();
	}
	cout << b.size() << '\n';
	for(auto i : b) cout << i << '\n';
}
