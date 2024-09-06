vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

const ll mod = 1e9 + 7;
const int N = 1e5 + 7;
ll dp[N], dp2[N], dp3[N];

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vi p = pi(t + '\0' + s);
    vi prev(n, -1);
    for (int i = 0; i < n; i++) {
        if (p[i + m + 1] == m) prev[i] = i;
        else if (i > 0) prev[i] = prev[i - 1];
    } 
    for (int i = 0; i < n; i++) {
        if (prev[i] != -1) dp[i] = (prev[i] - m + 2) % mod;
        if (prev[i] >= m) {
            dp[i] = (dp[i] + dp3[prev[i] - m]) % mod;
        }
        if (i > 0) {
            dp2[i] = dp2[i-1];
            dp3[i] = dp3[i-1];
        }
        dp2[i] = (dp2[i] + dp[i]) % mod;
        dp3[i] = (dp3[i] + dp2[i]) % mod;
    }
    cout << dp2[n - 1] << "\n";
}
