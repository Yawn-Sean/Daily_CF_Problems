void solve(){
	int n, s;
	cin >> n >> s;
	int cnt1 = 0, cnt2 = 0, tot = 0, ans = 0;
	vector<pii> v1, v2;
	for(int i = 1; i <= n; i ++){
		int c, a, b;
		cin >> c >> a >> b;
		if(a >= b){
			cnt1 += c;
			ans += c * a;
			v1.push_back({a - b, c});
		}
		else{
			cnt2 += c;
			ans += c * b;
			v2.push_back({b - a, c});
		}
		tot += c;
	}
	if((cnt1 + s - 1) / s + (cnt2 + s - 1) / s == (tot + s - 1) / s){
		return cout << ans << '\n', void();
	}
	int mn1 = 0, mn2 = 0;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int rm1 = cnt1 % s, rm2 = cnt2 % s;
	for(auto [x, c] : v1){
		c = min(c, rm1);
		rm1 -= c;
		mn1 += c * x;
	}
	for(auto [x, c] : v2){
		c = min(c, rm2);
		rm2 -= c;
		mn2 += c * x;
	}
	cout << ans - min(mn1, mn2) << '\n';
}
