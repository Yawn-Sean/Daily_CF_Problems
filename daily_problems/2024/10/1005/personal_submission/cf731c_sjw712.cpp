void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> c(n + 1);
	for(int i = 1; i <= n; i ++) cin >> c[i];
	DSU dsu(n + 1);
	for(int i = 1; i <= m; i ++){
		int l, r;
		cin >> l >> r;
		dsu.merge(l, r);
	}
	vector<unordered_map<int, int>> v(n + 1);
	vector<int> mx(n + 1);
	for(int i = 1; i <= n; i ++){
		int j = dsu.find(i);
		v[j][c[i]] = v[j][c[i]] + 1;
		mx[j] = max(mx[j], v[j][c[i]]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++){
		if(i == dsu.find(i)){
			ans += dsu.size(i) - mx[i]; 
		}
	}
	cout << ans << '\n';
}
