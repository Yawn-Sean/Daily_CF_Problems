void solve(){
	int n, m;
	cin >> n;
	vector<pii> a(n), b;
	vector<vector<pii>> q(n + 1);
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		a[i] = {x, i};
	}
	b = a;
	cin >> m;
	vector<int> ans(m);
	for(int i = 0; i < m; i ++){
		int k, pos;
		cin >> k >> pos;
		q[k].push_back({pos, i});
	}
	sort(a.begin(), a.end(), [](pii a, pii b){
		if(a.x != b.x) return a.x > b.x;
		return a.y < b.y;
	});
	ordered_set ost;
	for(int i = 0; i < n; i ++){
		ost.insert(a[i].y);
		for(auto [pos, idx] : q[i + 1]){
			ans[idx] = b[*ost.find_by_order(pos - 1)].x;
		}
	}
	for(int i = 0; i < m; i ++) cout << ans[i] << endl;
}
