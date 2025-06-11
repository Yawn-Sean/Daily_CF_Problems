const int mod = 1e9 + 7;
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
struct Comb {
    vector<int> fac, ifac;
    Comb(int n) : fac(n + 1), ifac(n + 1) {
        fac[0] = 1;
        for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
        ifac[n] = inv(fac[n]);
        for (int i = n; i; --i) ifac[i - 1] = ifac[i] * i % mod;
    }
    int binom(int a, int b) {
        return fac[a] * ifac[b] % mod * ifac[a - b] % mod;
    }
}comb(1e6);
int dp[100010][2];
int f(int n, int m, int g){
	if(n < 0 || m < 0) return 0;
	if(dp[n][g] != -1) return dp[n][g];
	if(n == 0 && m == 0) return dp[n][g] = 1;
	if(n + m == 1){
		if(n == 1) return dp[n][g] = (g == 0);
		else return dp[n][g] = (g == 1);
	}
	int ans = 0;
	if(g == 0){
		ans = (ans + f(n - 1, m, 1)) % mod;
		if(m > 0){
			m --;
			if(n) ans = (ans + comb.binom(n + m, m)) % mod;
			else ans = (ans + 1) % mod;
		}
	}
	else ans = (ans + f(n - 1, m, 0)) % mod;
	return dp[n][g] = ans;
}
void solve(){
	int n, m, g;
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> g;
	cout << f(n, m, g);

}
