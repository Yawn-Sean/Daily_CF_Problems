cin >> n;
	d[1] = 1;
	vector<vector<int>> g(n + 1);
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		d[i] = d[p[i]] + 1;
		g[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) cin >> s[i];
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		if (d[i] % 2 == 0) {
			int sz = g[i].size();
			if (sz) {
				int mn = 1e9;
				for (auto e : g[i]) mn = min(mn, s[e] - s[p[i]]);
				if (mn < 0) {
					cout << -1 << endl;
					return 0;
				}
				res += mn;
				s[i] = mn + s[p[i]];
			}
		}
		else res += s[i] - s[p[i]];
	}
	cout << res << endl;
