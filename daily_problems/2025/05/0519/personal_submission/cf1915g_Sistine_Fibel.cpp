

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> grid(n);
	vector<int > a(n);
	for(int i = 0, u, v, w; i < m; i ++){
		cin >> u >> v >> w;
		u --, v --;
		grid[u].pb({v, w});
		grid[v].pb({u, w});
	}
	for(auto &c : a)
		cin >> c;
	priority_queue<array<int, 3>> q;
	q.push({0, 0, 0});
	int ans = 1e9; //笑炸了，这里用0x3f3f3f3f3f3f3f3f会死test26
	vector<vector<bool >> st(n, vector<bool > (n));
	while(q.size()){
		auto [d, c, i] = q.top();
		q.pop();
		d =- d;
		if(st[c][i]) 
			continue;
		st[c][i] = 1;
		if(c == n - 1) 
			ans = min(ans, d);
		for(auto [u, w] : grid[c]){
			int next = i;
			if(a[u] < a[i]) 
				next = u;
			q.push({- (d + 1LL * a[i] * w), u, next});
		}
	}
	cout << ans << endl;
}
