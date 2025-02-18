void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(n == 1 || n == 2) return cout << "Alice" << '\n', void();
	int mx1 = 1, mx2 = 1;
	for(int i = 2; i <= n; i ++){
		if(a[i] > a[i - 1]) mx1 ++;
		else break;
	}
	for(int i = n - 1; i >= 1; i --){
		if(a[i] > a[i + 1]) mx2 ++;
		else break;
	}
	if(mx1 % 2 == 0 && mx2 % 2 == 0) cout << "Bob" << '\n';
	else  cout << "Alice" << '\n';
}
