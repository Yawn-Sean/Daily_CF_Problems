const int mod = 1e9 + 7;
void solve(){
	int n, x, y;
	cin >> n >> x >> y;
	vector<pii> a(n);
	set<pii> s;
	for(int i = 0; i < n; i ++){
		cin >> a[i].x >> a[i].y;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; i ++){
		ans = (ans + x + y * (a[i].y - a[i].x) % mod) % mod;
	}
	
	for(int i = 0; i < n; i ++){
		auto it = s.lower_bound({a[i].x, -1});
		if(it == s.begin()){
			s.insert({a[i].y, i});
			continue;
		}
		it --;
		auto k = *it;
		if(y * (a[i].x - k.x) <= x){
			ans = (ans + y * (a[i].x - k.x) % mod - x + mod) % mod;
			s.erase({k.x, k.y});
		}
		s.insert({a[i].y, i});
	}
	cout << ans << '\n';
}
