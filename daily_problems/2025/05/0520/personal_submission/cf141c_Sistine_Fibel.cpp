
void solve(){
	int ans[3100];
	int n;
	cin >> n;
	pair<int, string> a[n];
	for(auto &[x, y] : a)
		cin >> y >> x;
	sort(a, a + n);
	for(int i = 0; i < n; i ++){
		int L = i - a[i].first;
		if(L < 0){
			cout << -1;
			return;
		}
		ans[i] = L;
		for(int j = 0; j < i; j ++)
			if(ans[j] >= ans[i])
				ans[j] ++;
	}
	for(int i = 0; i < n; i ++)
		cout << a[i].second << ' ' << 3000 + ans[i] << endl;
}
