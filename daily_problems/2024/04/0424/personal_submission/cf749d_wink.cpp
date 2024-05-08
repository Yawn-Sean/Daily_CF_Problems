void solve()
{
	int n;
	cin >> n;

	vector<vector<int>> e(n);
	vector<pair<int, int>> c;
	vector<int> st(n);
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		a--;
		e[a].push_back(b);
	}
	for (int i = 0; i < n; ++i)
	{
		if (sz(e[i]))
		{
			c.push_back({e[i].back(), i});
		}
	}
	int m = sz(c);
	sort(c.begin(), c.end());

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int k;
		cin >> k;
		vector<int> pos(k);
		for (int j = 0; j < k; ++j)
		{
			cin >> pos[j];
			pos[j]--;
			st[pos[j]] = 1;
		}

		// 找到有效竞拍者最大和次大
		int u = -1, v = -1;
		for (int j = m - 1; j >= 0; --j)
		{
			if (st[c[j].second] == 0)
			{
				if (u == -1)
				{
					u = c[j].second;
				}
				else
				{
					v = c[j].second;
					break;
				}
			}
		}

		for (int j = 0; j < k; ++j)
		{
			st[pos[j]] = 0;
		}

		if (u == -1)
		{
			cout << "0 0" << '\n';
			continue;
		}
		int w = 0;
		if (v != -1)
		{
			w = e[v].back();
		}

		int idx = lower_bound(e[u].begin(), e[u].end(), w) - e[u].begin();
		cout << u + 1 << " " << e[u][idx] << '\n';
	}
}
