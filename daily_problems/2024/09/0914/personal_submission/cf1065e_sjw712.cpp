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
	int n, m, a;
	cin >> n >> m >> a;
	vector<int> b(m + 1);
	b[0] = 0;
	for(int i = 1; i <= m; i ++) cin >> b[i];
	int ans = 1;
	for(int i = 1; i <= m; i ++){
		int k = qmi(a, b[i] - b[i - 1]);
		ans = (ans * (k % mod * (k - 1) % mod * inv(2) % mod + k % mod) % mod) % mod;
	}
	ans = (ans * qmi(a, n - b[m] * 2) % mod);
	cout << ans << '\n';
}
