void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i ++) ans ^= a[i];
	for(int i = 1; i <= n; i ++){
		b[i] = b[i - 1] ^ i;
	}
	for(int i = 1; i <= n; i ++){
		if(i == n) ans ^= b[n - 1];
		else ans ^= b[n % i];
		if((n / i) % 2 == 1 && i != n) ans ^= b[i - 1];
	}
	cout << ans << '\n';
}
