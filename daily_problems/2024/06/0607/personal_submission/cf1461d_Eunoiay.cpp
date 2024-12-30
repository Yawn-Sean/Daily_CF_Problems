void solve() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	set<i64> S;
	function<void(int, int)> dfs = [&](int l, int r) {
		if (l > r) {
			return;
		}

		int mx = 0, mn = 1e6;
		i64 sum = 0;
		for (int i = l; i <= r; ++i) {
			mx = max(a[i], mx);
			mn = min(a[i], mn);
			sum += a[i];
		}
		S.insert(sum);

		if (l == r) {
			return;
		}

		int mid = (mx + mn) / 2;
		vector<int> b, c;
		for (int i = l; i <= r; ++i) {
			if (a[i] <= mid) {
				b.push_back(a[i]);
			} else {
				c.push_back(a[i]);
			}
		}

		int x = b.size();
		int y = c.size();
		for (int i = l, j = 0; i <= r; ++i, ++j) {
			if (j < x) {
				a[i] = b[j];
			} else {
				a[i] = c[j - x];
			}
		}

		bool same = true;
		for (int i = l; i <= r; ++i) {
			if (a[i] != mid) {
				same = false;
				break;
			}
		}
		if (same) {
			return;
		}

		dfs(l, l + x - 1);
		dfs(l + x, r);
	};	
	dfs(0, n - 1);

	while (q--) {
		int s;
		cin >> s;	

		cout << (S.count(s) ? "YES" : "NO") << "\n";
	}
}
