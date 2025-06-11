int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, D;
	cin >> n >> m >> D;

	vector<pair<int, int>> edges(m);
	vector<int> e;
	for (auto &[u, v] : edges) {
		cin >> u >> v;
		--u, --v;
		if (u == 0 || v == 0) {
			e.push_back(max(u, v));
		}
	}

	if (e.size() < D) {
		cout << "NO\n";
		return 0;
	}

	DSU dsu(n);
	for (auto [u, v] : edges) {
		if (u && v) {
			dsu.merge(u, v);
		}
	}

	vector<int> block(n);
	int cnt = 0;
	for (int i = 1; i < n; ++i) {
		block[i] = dsu.find(i);
		if (dsu.root(i)) {
			cnt += 1;
		}
	}	
	if (cnt > D) {
		cout << "NO\n";
		return 0;
	}

	dsu.init(n);
	vector<int> vis(n);
	int need = D - cnt;

	vector<pair<int, int>> ans;
	for (auto v : e) {
		int i = block[v];
		if (!vis[i] || --need >= 0) {
			vis[i] = 1;
			dsu.merge(0, v);
			ans.emplace_back(1, v + 1);
		}
	}
	for (auto [u, v] : edges) {
		if (u && v && dsu.merge(u, v)) {
			ans.emplace_back(u + 1, v + 1);
		}
	}

	cout << "YES\n";
	for (auto [u, v] : ans) {
		cout << u << " " << v << "\n";
	}

	return 0;
}
