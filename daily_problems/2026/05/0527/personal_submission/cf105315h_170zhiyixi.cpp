int t;
	cin >> t; 
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<pii>v;
		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({b, a});
		} 
		sort(v.begin(), v.end(), greater<pii>());
		int ma = 0;
		int sum = 0;
		priority_queue<int, vector<int>, greater<int> >q;
		for (int i = n - 1 - k + 1; i <= n - 1; i++) {
			if (i == n - 1 - k + 1) {
				ma -= v[i].ff;
			}
			sum += v[i].ss;
			q.push(v[i].ss);
		}
		
		ma += sum;
		for (int i = n - 1 - k + 1 - 1; i >= 0; i--) {
			sum -= q.top();
			q.pop();
			sum += v[i].ss;
			q.push(v[i].ss);
			ma = max(ma, sum - v[i].ff);
		} 
		cout << ma << endl;
	}
