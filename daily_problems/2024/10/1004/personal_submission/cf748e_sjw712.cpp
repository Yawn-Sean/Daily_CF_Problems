void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> cnt(2e7 + 10);
	for(int i = 1; i <= n; i ++){
		int x;
		cin >> x;
		cnt[x] ++;
	}
	int cur = 0;
	for(int i = 1e7; i >= 1; i --){
		cur += cnt[i];
		cur += cnt[i * 2 + 1];
		cnt[i] += cnt[i * 2 + 1];
		cnt[i + 1] += cnt[i * 2 + 1];
		cur += cnt[i * 2];
		cnt[i] += cnt[i * 2] * 2;
		if(cur >= k){
			cout << i << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}
