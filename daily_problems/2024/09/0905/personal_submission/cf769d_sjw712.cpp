void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> cnt(10010);
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		cnt[x] ++;
	}
	int ans = 0, sum = 0;
	auto dfs = [&](auto self, int u, int x, int used)->void{
		if(k - used > u + 1) return;
		if(used == k){
			if(x <= 10000){
				sum += cnt[x];
			}
			return;
		}
		self(self, u - 1, x ^ (1 << u), used + 1);
		self(self, u - 1, x, used);
	};
	for(int i = 0; i <= 10000; i ++){
		if(cnt[i]){
			if(k == 0){
				ans += cnt[i] * (cnt[i] - 1) / 2;
				continue;
			}
			sum = 0;
			dfs(dfs, 13, i, 0);
			ans += cnt[i] * sum;
		}
	}
	cout << (k == 0 ? ans : ans / 2) << '\n';
}
