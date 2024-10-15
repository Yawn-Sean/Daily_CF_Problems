void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	int l = 0, r = 0;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(i > 1) r = max(r, a[i] - a[i - 1]);
	}
	if(n == 1) return cout << 0 << '\n', void();
	auto check = [&](int x)->bool{
		vector<int> dp(n + 1, 1);
		//dp[i] 表示前i个数，第i个数不改的时候最多保留多少个数
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j < i; j ++){
				if(abs(a[i] - a[j]) <= x * (i - j)){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			} 
			if(dp[i] + k >= n) return true;
		}
		return false;
	};
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
}
