void solve(){
	int n, l, t;
	cin >> n >> l >> t;
	vector<int> a(2 * n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		a[i + n] = a[i] + l;
	}
	int ans = 0;
	int k = 2 * t / l, d = (2 * t) % l;
	ans += n * (n - 1) * k;
	for(int i = 1, j = 1; i <= n; i ++){
		while(j <= 2 * n && a[j] - a[i] <= d){
			j ++;
		}
		j --;
		ans += j - i;
	}
	cout << fixed << setprecision(10) << 0.25 * ans << '\n';
}
