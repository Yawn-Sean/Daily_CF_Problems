void solve(){
	int n;
	cin >> n;
	vector<int> l(n + 1), p(n + 1);
	for(int i = 1; i <= n; i ++) cin >> l[i] >> p[i];
	vector<int> ord(n + 1);
	iota(ord.begin() + 1, ord.end(), 1);
	sort(ord.begin() + 1, ord.end(), [&](int i, int j){
		return p[i] * l[i] * (100 - p[j]) > p[j] * l[j] * (100 - p[i]);
	});
	double ans = 0, sum = 0;
	for(int i = 1; i <= n; i ++){
		ans += (1. - (double)p[ord[i]] / 100) * sum + l[ord[i]];
		sum += (double)p[ord[i]] / 100 * l[ord[i]];
	}
	cout << fixed << setprecision(10) << ans << '\n';
}
