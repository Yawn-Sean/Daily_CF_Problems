void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	auto o = a;
	sort(o.begin(), o.end());
	o.erase(unique(o.begin(), o.end()), o.end());	

	auto find = [&](int x) {
		return lower_bound(o.begin(), o.end(), x) - o.begin() + 1;
	};

	Fenwick<int> fen(o.size());
	i64 ans = 0;
	for (int i = 0; i < n; ++i) {
		int k = find(a[i]);
		int x = fen.query(k - 1);
		int y = fen.rangeQuery(k + 1, o.size());
		if (x < y) {
			ans += x;
		} else {
			ans += y;
		}
		fen.modify(k, 1);
	}
	cout << ans << "\n";
}
