const int INF = 9e18;
void solve(){
	int n, m, b;
	cin >> n >> m >> b;
	vector<vector<int>> a(n + 1, vector<int>(3));
	for(int i = 1; i <= n; i ++){
		int x, k, c;
		cin >> x >> k >> c;
		int tmp = 0;
		while(c --){
			int d;
			cin >> d;
			tmp |= (1 << (d - 1));
		}
		a[i] = {tmp, x, k};
	}
	int ans = INF;
	sort(a.begin() + 1, a.end(), [](vector<int> a, vector<int> b){
		return a[2] < b[2];
	});
	vector<int> dp(1 << m, INF);
	dp[0] = 0;
	for(int i = 1; i <= n; i ++){
		vector<int> ndp = dp;
		for(int j = 0; j < (1 << m); j ++){
			if(dp[j] != INF){
				ndp[j | a[i][0]] = min(ndp[j | a[i][0]], ndp[j] + a[i][1]);
			}
		}
		dp.swap(ndp);
		if(dp[(1 << m) - 1] != INF) ans = min(ans, dp[(1 << m) - 1] + a[i][2] * b);
	}
	if(ans == 9e18) ans = -1;
	cout << ans << '\n';
}	
