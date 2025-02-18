void solve(){
	int n, m;
	cin >> m >> n;
	vector<int> a(n + 2);
	for(int i = 1; i <= n; i ++) cin >> a[i];
	a[0] = a[1], a[n + 1] = a[n];
	if(m == 1) return cout << 0 << '\n', void();
	int sum = 0;
	for(int i = 2; i <= n; i ++) sum += abs(a[i] - a[i - 1]);
	int ans = sum;
	vector<vector<int>> g(m + 1);
	for(int i = 1; i <= n; i ++){
		if(a[i] != a[i - 1]){
			g[a[i]].push_back(a[i - 1]);
		}
		if(a[i] != a[i + 1]){
			g[a[i]].push_back(a[i + 1]);
		}
	}
	for(int i = 1; i <= m; i ++) sort(g[i].begin(), g[i].end());
	for(int i = 1; i <= m; i ++){
		if(g[i].size()){
			int k = g[i][g[i].size() / 2];
			int res1 = 0, res2 = 0;
			for(int j = 0; j < g[i].size(); j ++){
				res1 += abs(i - g[i][j]);
				res2 += abs(k - g[i][j]);
			}
			ans = min(ans, sum - res1 + res2);
		}
	}
	cout << ans << '\n';
}
