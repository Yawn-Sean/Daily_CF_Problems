void solve(){
	int n, m;
	string s, t;
	cin >> n >> s >> m;
	s = ' ' + s;
	vector<int> f(n + 1, 1e9), g(n + 1, 1e9), p(n + 1);
	vector<vector<int>> q(n + 1, vector<int>(2));
	for(int i = 1; i <= n; i ++){
		p[i] = p[i - 1] + (s[i] == '?');
		if(s[i] != 'b') q[i][1] = q[i - 1][0] + 1;
		if(s[i] != 'a') q[i][0] = q[i - 1][1] + 1;
	}
	for(int i = 0; i <= n; i ++){
		if(i < m){
			f[i] = g[i] = 0;
			continue;
		}
		f[i] = f[i - 1];
		g[i] = g[i - 1];
		if(q[i][m & 1] >= m){
			if(f[i - m] + 1 > f[i]){
				f[i] = f[i - m] + 1;
				g[i] = g[i - m] + p[i] - p[i - m];
			}
			if(f[i - m] + 1 == f[i]){
				g[i] = min(g[i], g[i - m] + p[i] - p[i - m]);
			}
		}
	}
	cout << g[n] << endl;
}
