void solve(){
	int n, x1, x2;
	cin >> n >> x1 >> x2;
	vector<pii> p(n);
	for(int i = 0; i < n; i ++){
		int k, b;
		cin >> k >> b;
		p[i] = {k * x1 + b, k * x2 + b};
	}
	sort(p.begin(), p.end());
	for(int i = 1; i < n; i ++){
		if(p[i].y < p[i - 1].y) return cout << "YES" << '\n', void();
	}
	cout << "NO" << '\n';
}	
