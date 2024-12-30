void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	vector<bool> used(n + 1);
	map<int, int> mp;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		mp[a[i]] ++;
	}
	for(int i = 1; i <= n; i ++) cin >> b[i];
	int ans = 0;
	for(auto [k, v] : mp){
		if(v > 1){
			for(int i = 1; i <= n; i ++){
				if(!used[i] && (a[i] & k) == a[i]){
					used[i] = true;
					ans += b[i];
				}
			}
		}
	}
	cout << ans << '\n';
}
