void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= k; i ++){
		if(n % i != i - 1) return cout << "No" << '\n', void();
	}
	cout << "Yes" << '\n';
}
