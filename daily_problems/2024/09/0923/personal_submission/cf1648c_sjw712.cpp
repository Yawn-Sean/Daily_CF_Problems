const int mod = 998244353, N = 200010;
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
int tr[N];
int lowbit(int x){
	return x & -x;
}
void add(int x, int v){
	for(int i = x; i < N; i += lowbit(i)){
		tr[i] += v;
	}
}
int query(int x){
	int res = 0;
	for(int i = x; i; i -= lowbit(i)){
		res = (res + tr[i]) % mod;
	}
	return res;
}
void solve(){
	int n, m, mul = 1;
	cin >> n >> m;
	vector<int> s(n + 1), t(m + 1), cnt(N), fac(N);
	fac[0] = 1;
	for(int i = 1; i < N; i ++){
		fac[i] = fac[i - 1] * i % mod;
	}
	for(int i = 1; i <= n; i ++){
		cin >> s[i];
		add(s[i], 1);
		cnt[s[i]] ++;
	}
	for(int i = 1; i < N; i ++){
		if(cnt[i]) mul = mul * fac[cnt[i]] % mod;
	}
	for(int i = 1; i <= m; i ++) cin >> t[i];
	int ans = 0;
	for(int i = 1; i <= n + 1; i ++){
		if(i == n + 1){
			if(n < m) ans = (ans + 1) % mod;
			break;
		}
		if(i > m) break;
		ans = (ans + query(t[i] - 1) * fac[n - i] % mod * inv(mul) % mod) % mod;
		if(cnt[t[i]]){
			mul = mul * inv(cnt[t[i]]) % mod;
			cnt[t[i]] --;
			add(t[i], -1);
		}
		else break;

	}
	cout << ans << '\n';
}
