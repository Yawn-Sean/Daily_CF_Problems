void solve()
{
	int n;
	cin >> n;

	vector<int> l(n), r(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> l[i] >> r[i];
	}

	vector<int> premxl(n, -2e9), premir(n, 2e9), sufmxl(n, -2e9), sufmir(n, 2e9);
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			premxl[i] = l[i];
			premir[i] = r[i];
		}
		else
		{
			premxl[i] = max(premxl[i - 1], l[i]);
			premir[i] = min(premir[i - 1], r[i]);
		}
	}
	for (int i = n - 1; i >= 0; --i)
	{
		if (i == n - 1)
		{
			sufmxl[i] = l[i];
			sufmir[i] = r[i];
		}
		else
		{
			sufmxl[i] = max(sufmxl[i + 1], l[i]);
			sufmir[i] = min(sufmir[i + 1], r[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			ans = max(ans, max(0, sufmir[i + 1] - sufmxl[i + 1]));
		}
		else if (i == n - 1)
		{
			ans = max(ans, max(0, premir[i - 1] - premxl[i - 1]));
		}
		else
		{
			int gl = max(premxl[i - 1], sufmxl[i + 1]);
			int gr = min(premir[i - 1], sufmir[i + 1]);
			ans = max(ans, max(0, gr - gl));
		}
	}

	cout << ans << '\n';
}
