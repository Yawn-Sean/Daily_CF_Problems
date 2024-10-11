void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			cin >> a[i][j]; 
		}
	}
	vector<vector<int>> dp0(n + 2, vector<int>(m + 2));
	vector<vector<int>> dp1(n + 2, vector<int>(m + 2));
	vector<vector<int>> dp2(n + 2, vector<int>(m + 2));
	vector<vector<int>> dp3(n + 2, vector<int>(m + 2));
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			dp0[i][j] = max(dp0[i - 1][j], dp0[i][j - 1]) + a[i][j];
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = m; j >= 1; j --){
			dp1[i][j] = max(dp1[i - 1][j], dp1[i][j + 1]) + a[i][j];
		}
	}
	for(int i = n; i >= 1; i --){
		for(int j = m; j >= 1; j --){
			dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + a[i][j];
		}
	}
	for(int i = n; i >= 1; i --){
		for(int j = 1; j <= m; j ++){
			dp3[i][j] = max(dp3[i + 1][j], dp3[i][j - 1]) + a[i][j];
		}
	}
	int ans = 0;
	for(int i = 2; i <= n - 1; i ++){
		for(int j = 2; j <= m - 1; j ++){
			ans = max(ans, dp0[i][j - 1] + dp1[i - 1][j] + dp2[i][j + 1] + dp3[i + 1][j]);
			ans = max(ans, dp0[i - 1][j] + dp1[i][j + 1] + dp2[i + 1][j] + dp3[i][j - 1]);
		}
	}
	cout << ans << '\n';
}
