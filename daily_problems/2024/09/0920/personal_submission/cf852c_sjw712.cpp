void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n),ans(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	iota(b.begin(), b.end(), 0);
	sort(b.begin(), b.end(), [&](int x, int y){
		return a[x] + a[(x + 1) % n] < a[y] + a[(y + 1) % n];
	});
	for(int i = 0; i < n; i ++){
		ans[b[i]] = i;
	}
	for(auto i : ans) cout << i << " ";
}
