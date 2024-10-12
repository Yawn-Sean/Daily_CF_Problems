void solve(){
	int a, b, h, w, n;
	cin >> a >> b >> h >> w >> n;
	vector<int> c(n);
	for(int i = 0; i < n; i ++) cin >> c[i];
	sort(c.begin(), c.end(), greater());
	n = min(n, 34ll);
	auto work = [&](int x, int y)->int{
		map<pii, int> mp;
		mp[{x, y}] = 0;
		for(int i = 0; i < n; i ++){
			for(auto [t, _] : mp){
				int x = t.x, y = t.y;
				int nx = (x + c[i] - 1) / c[i];
				int ny = (y + c[i] - 1) / c[i];
				if(!mp.count({nx, y})){
					mp[{nx, y}] = mp[{x, y}] + 1;
				}
				if(!mp.count({x, ny})){
					mp[{x, ny}] = mp[{x, y}] + 1;
				}
			}
		}
		return mp.count({1, 1}) ? mp[{1, 1}] : 1e18;
	};
	int ans = 1e18;
	ans = min({ans, work((a + h - 1) / h, (b + w - 1) / w), work((a + w - 1) / w, (b + h - 1) / h)});
	if(ans == 1e18) ans = -1;
	cout << ans << '\n';
}
