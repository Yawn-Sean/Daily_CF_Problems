void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> cnt1(1e5 + 1), cnt2(1e5 + 1);
	vector<int> h(k + 1);
	vector<vector<int>> dp(n + 1, vector<int>(n * k + 1));
	for(int i = 1; i <= n * k; i ++){
		int x;
		cin >> x;
		cnt1[x] ++;
	}
	for(int i = 1; i <= n; i ++){
		int x;
		cin >> x;
		cnt2[x] ++;
	}
	for(int i = 1; i <= k; i ++){
		cin >> h[i];
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n * k; j ++){
			for(int x = 1; x <= min(j, k); x ++){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + h[x]);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= 1e5; i ++){
		ans += dp[cnt2[i]][cnt1[i]];
	}
	cout << ans << '\n';
}
