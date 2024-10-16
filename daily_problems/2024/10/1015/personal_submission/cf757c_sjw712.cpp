const int mod = 1e9 + 7;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m + 1);
	map<vector<int>, int> mp;
	for(int i = 0; i < n; i ++){
		int k;
		cin >> k;
		for(int j = 0; j < k; j ++){
			int x;
			cin >> x;
			a[x].push_back(i);
		}
	}
	int ans = 1;
	for(int i = 1; i <= m; i ++){
		mp[a[i]] ++;
		ans = ans * mp[a[i]] % mod;
	}
	cout << ans << '\n';
}
