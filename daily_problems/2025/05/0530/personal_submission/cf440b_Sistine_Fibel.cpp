	int n;
	cin >> n;
	vector<int > a(n, 0);
	int sum = 0;
	for(auto &c : a)
		cin >> c, sum += c;
	int m = sum / n, ans = 0;
	for(int i = 0; i < n - 1; i ++){
		if(a[i] < m)
			ans += m - a[i], a[i + 1] -= m - a[i];
		else
			ans += a[i] - m, a[i + 1] += a[i] - m;
	}
	cout << ans << endl;

