void solve(){
	int n, ans = 1e9;
	cin >> n;
	vector<int> a(n * 2 + 1), pre(n + 1), suf(n + 1);
	for(int i = 1; i <= n * 2; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		pre[i] = pre[i - 1] + (a[i] == 1 ? 1 : -1);
	}
	unordered_map<int, int> mp;
	mp[0] = 0;
	for(int i = n * 2; i >= n + 1; i --){
		suf[n * 2 - i + 1] = suf[n * 2 - i] + (a[i] == 1 ? 1 : -1);
		mp[suf[n * 2 - i + 1]] = n * 2 - i + 1;
	}
	for(int i = 0; i <= n; i ++){
		if(mp.count(-pre[i])){
			ans = min(ans, 2 * n - i - mp[-pre[i]]);
		}
	}
	cout << ans << '\n';
}
