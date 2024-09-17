void solve(){
	int n, s;
	cin >> n >> s;
	vector<int> a(n + 1), cnt1(n + 1), cnt2(n + 1);
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		if(i == s){
			if(a[i]) ans ++;
		} 
		else{
			cnt1[a[i]] = 1;
			cnt2[a[i]] ++;
		}
	}
	if(n == 1) return cout << ans << '\n', void();
	int mn = 1e18, sum1 = 0, sum2 = 0;
	for(int i = 1; i <= n; i ++){
		sum1 += cnt1[i], sum2 += cnt2[i];
		mn = min(mn, max(i - sum1, n - 1 - sum2));
	}
	cout << ans + mn << '\n';
}
