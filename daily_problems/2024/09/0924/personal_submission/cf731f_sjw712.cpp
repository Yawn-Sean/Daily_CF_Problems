void solve(){
	int n, ans = 0;
	cin >> n;
	vector<int> a(n), s(2e5 + 10);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		s[a[i]] ++;
	}
	for(int i = 1; i <= 2e5; i ++) s[i] += s[i - 1];
	for(int i = 1; i <= 2e5; i ++){
		if(!(s[i] - s[i - 1])) continue;
		int res = 0;
		for(int j = i; j <= 2e5; j += i){
			res += j * (s[min((int)2e5, j + i - 1)] - s[j - 1]);
		}
		ans = max(ans, res);
	}
	cout << ans << '\n';
}
