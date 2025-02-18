void solve(){
	int n;
	cin >> n;
	vector<int> p(n + 1), b(n + 1);
	for(int i = 1; i <= n; i ++) cin >> p[i];
	for(int i = 1; i <= n; i ++) cin >> b[i];
	int cnt = 0;
	vector<bool> vis(n + 1);
	auto dfs = [&](auto self, int u)->void{
		if(vis[u]) return;
		vis[u] = true;
		self(self, p[u]);
	};
	for(int i = 1; i <= n; i ++){
		if(!vis[i]){
			dfs(dfs, i);
			cnt ++;
		}
	}
	int ans = cnt == 1 ? 0 : cnt;
	int cnt1 = count(b.begin() + 1, b.end(), 1);
	if(cnt1 % 2 == 0) ans ++;
	cout << ans << '\n';
}
