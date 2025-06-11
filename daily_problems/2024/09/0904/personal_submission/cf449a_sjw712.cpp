void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	if(k > n + m - 2) return cout << -1 << '\n', void();
	int ans = 0;
	int tmp;
	if(k > m - 1){
		tmp = k - m + 1;
		ans = max(ans, n / (tmp + 1));
	}
	if(k > n - 1){
		tmp = k - n + 1;
		ans = max(ans, m / (tmp + 1));
	}
	ans = max(ans, max(n / (k + 1) * m, m / (k + 1) * n));
	cout << ans << "\n";
}
