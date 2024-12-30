const int mod = 1e9 + 7;
void solve(){
	int n;
	cin >> n;
	set<int> a, b;
	for(int i = 1; i <= n; i ++) a.insert(i);
	for(int i = 1; i <= n; i ++){
		int x;
		cin >> x;
		if(x == -1){
			b.insert(i);
		}
		else{
			a.erase(x);
		}
	}
	vector<int> d(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	d[1] = 0, d[2] = 1, dp[0][0] = 1;
	for(int i = 3; i <= n; i ++){
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % mod;
	}
	for(int i = 1; i <= n; i ++){
		dp[i][0] = dp[i - 1][0] * i % mod;
		dp[0][i] = d[i];
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			dp[i][j] = (i * dp[i - 1][j] % mod + j * dp[i][j - 1] % mod) % mod;
		}
	}
	int cnt = 0, ans = 0;
	for(auto i : a){
		if(b.count(i)) cnt ++;
	}
	cout << dp[a.size() - cnt][cnt] << '\n';
}
