void solve(){
	int n, m, a;
	cin >> n >> m >> a;
	vector<int> b(n), p(m);
	for(int i = 0; i < n; i ++) cin >> b[i];
	for(int i = 0; i < m; i ++) cin >> p[i];
	sort(p.begin(), p.end());
	sort(b.begin(), b.end(), greater());
	auto check = [&](int x)->bool{
		if(x < 0) return false;
		int tmp = a;
		for(int i = x, j = 0; i >= 0; i --, j ++){
			if(b[j] < p[i]){
				if(tmp >= p[i] - b[j]){
					tmp -= (p[i] - b[j]);
				}
				else return false;
			}
		}
		return true;
	};
	
	int l = -1, r = min(n - 1, m - 1);
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	if(l == -1) return cout << "0 0" << '\n', void();
	int ans = accumulate(p.begin(), p.begin() + l + 1, 0ll);
	cout << l + 1 << " " << max(0ll, ans - a) << '\n';
}
