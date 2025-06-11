const int mod = 998244353;
int qmi(int a, int b){
	int res = 1; 
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int inv(int x){
	return qmi(x, mod - 2);
}
void solve(){
	int n;
	cin >> n;
	int ans = 0;
	vector<vector<int>> a(1e6 + 10), b(n + 1);
	for(int i = 1; i <= n; i ++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j ++){
			int x;
			cin >> x;
			a[x].push_back(i);
			b[i].push_back(x);
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < b[i].size(); j ++){
			ans = (ans + inv(b[i].size()) * inv(n) % mod 
				* a[b[i][j]].size() % mod * inv(n) % mod) % mod;
		} 
	}
	cout << ans << '\n';
}
