const int mod = 1e9 + 7;
vector<int> kmp(string s) {
    int n = s.size();
    vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}
void add(int &a, int b){
	a += b;
	a %= mod;
}
void solve(){
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<int> p = kmp(t + "$" + s), pre(n + 1, -1);
	vector<int> f(n + 1), g(n + 1), h(n + 1);
	for(int i = 1; i <= n; i ++){
		if(p[i + m + 1] == m) pre[i] = i - m + 1;
		else pre[i] = pre[i - 1];
	}
	for(int i = 1; i <= n; i ++){
		if(pre[i] != -1) f[i] = pre[i];
		if(pre[i] >= 1){
			add(f[i], h[pre[i] - 1]);
		}
		add(g[i], g[i - 1] + f[i]);
		add(h[i], h[i - 1] + g[i]);
	}
	cout << g[n] << '\n';
}
