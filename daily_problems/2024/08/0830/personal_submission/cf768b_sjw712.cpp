void solve(){
	int n, l, r;
	cin >> n >> l >> r;
	int len = 1, x = n;
	while(x > 1){
		len = len << 1 | 1;
		x >>= 1;
	}
	auto dfs = [&](auto self, int n, int l, int r, int L, int R)->int{
		if(R < l || L > r || n == 0) return 0;
		if(n == 1) return 1;
		int mid = L + R >> 1;
		return self(self, n / 2, l, r, L, mid - 1) + self(self, n / 2, l, r, mid + 1, R) + self(self, n % 2, l, r, mid, mid);
	};
	cout << dfs(dfs, n, l, r, 1, len) << endl;
}
