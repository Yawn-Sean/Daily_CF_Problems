void solve(){
	int n, k;
	cin >> n >> k;
	int cnt = 2;
	int p = (n - k - 1 + k - 1) / k;
	int tot = n - 1 - k;
	cout << p + 1 + min(p, (tot - p + k - 2) / (k - 1)) + 1 << '\n';
	while(tot > 0){
		cout << 1 << " " << cnt << '\n';
		for(int j = 1; j <= p; j ++){
			cout << cnt << " " << cnt + 1 << '\n';
			cnt ++;
		}
		cnt ++;
		tot -= p;
		k --;
		if(k == 0) break;
		p = (tot + k - 1) / k;
	}
	for(int i = cnt; i <= n; i ++) cout << 1 << " " << i << '\n';
}
