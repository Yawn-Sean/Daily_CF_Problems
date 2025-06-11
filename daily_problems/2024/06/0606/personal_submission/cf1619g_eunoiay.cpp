void solve() {
	int n, k;
	cin >> n >> k;

	map<int, vector<pair<int, int>>> row, col;
	vector<int> t(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y >> t[i];		
		row[x].emplace_back(y, i);
		col[y].emplace_back(x, i);
	}

	DSU dsu(n);
	for (auto &[_, vec] : row) {
		sort(vec.begin(), vec.end());
		for (int i = 0; i + 1 < (int)vec.size(); ++i) {
			if (vec[i + 1].first - vec[i].first <= k){
				dsu.merge(vec[i + 1].second, vec[i].second);
			}
		}
	}
	for (auto &[_, vec] : col) {
		sort(vec.begin(), vec.end());
		for (int i = 0; i + 1 < (int)vec.size(); ++i) {
			if (vec[i + 1].first - vec[i].first <= k){
				dsu.merge(vec[i + 1].second, vec[i].second);
			}
		}
	}
	
	vector<int> e(n, inf);
	for (int i = 0; i < n; ++i) {
		int p = dsu.find(i);
		e[p] = min(e[p], t[i]);
	}
	sort(e.rbegin(), e.rend());

	int cur = -1;
	for (int i = 0; i < n; ++i) {
		if (e[i] == inf) {
			continue;
		}
		if (e[i] > cur) {
			cur += 1;
		}
	}
	cout << cur << "\n";
}
