void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	map<int, vector<pii>> mp;
	for(int i = 0; i < n; i ++){
		int x, vx, vy;
		cin >> x >> vx >> vy;
		mp[vy - a * vx].push_back({vx, vy});
	}
	int ans = 0;
	for(auto &[k, v] : mp){
		map<pii, int> mp2;
		for(int i = 0; i < v.size(); i ++) mp2[v[i]] ++;
		int sum = 0;
		for(auto [kk, vv] : mp2) sum += vv;
		for(auto [kk, vv] : mp2) ans += vv * (sum - vv);
	}
	cout << ans << '\n';
}
