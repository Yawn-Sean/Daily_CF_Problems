void solve()
{
	int n, m;
	cin >> n >> m;
 
	vector<array<int, 2>> edge(m);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		edge[i] = {u, v};
	}
 
	auto check = [&](int mid)
	{
		vector<int> deg(n);
		vector<vector<int>> e(n);
		queue<int> q;
 
		for (int i = 0; i < mid; ++i)
		{
			int u = edge[i][0], v = edge[i][1];
			e[u].push_back(v);
			deg[v]++;
		}
 
		for (int i = 0; i < n; ++i)
		{
			if (deg[i] == 0)
			{
				q.push(i);
			}
		}
 
		while (sz(q))
		{
			if (sz(q) > 1)
			{
				return false;
			}
			auto p = q.front();
			q.pop();
			for (auto v : e[p])
			{
				deg[v]--;
				if (deg[v] == 0)
				{
					q.push(v);
				}
			}
		}
 
		return true;
	};
 
	int l = 1, r = m;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
 
	if (check(r))
		cout << r << '\n';
	else
		cout << -1 << '\n';
}
