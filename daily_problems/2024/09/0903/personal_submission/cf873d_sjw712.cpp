void solve(){
	int n, k;
	cin >> n >> k;
	if(k % 2 == 0) return cout << -1 << '\n', void();
	vector<int> ans(n);
	iota(ans.begin(), ans.end(), 1);
	k /= 2;
	auto dfs = [&](auto self, int l, int r)->void{
		if(k == 0 || l + 1 == r) return;
		int mid = l + r >> 1;
		k --;
		swap(ans[mid], ans[mid - 1]);
		self(self, l, mid);
		self(self, mid, r);

	};
	dfs(dfs, 0, n);
	if(k) cout << -1 << '\n';
	else{
		for(auto i : ans) cout << i << " ";
		cout << '\n';
	}
}
