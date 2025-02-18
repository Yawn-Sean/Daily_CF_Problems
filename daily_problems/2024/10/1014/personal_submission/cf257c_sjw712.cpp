void solve(){
	int n;
	cin >> n;
	vector<double> a(n);
	for(int i = 0; i < n; i ++){
		double x, y;
		cin >> x >> y;
		a[i] = atan2l(y, x) / pi * 180;
	}
	sort(a.begin(), a.end());
	double ans = 1e18;
	for(int i = 1; i < n; i ++){
		ans = min(ans, 360 - (a[i] - a[i - 1]));
	}
	ans = min(ans, a[n - 1] - a[0]);
	cout << fixed << setprecision(10) << ans << '\n';
}
