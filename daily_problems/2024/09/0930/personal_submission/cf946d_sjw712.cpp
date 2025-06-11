void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> f(n + 1, vector<int>(k + 1, 1e9));
	vector<vector<int>> g(n + 1);
	vector<string> s(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> s[i];
		s[i] = ' ' + s[i];
	} 
	for(int i = 1; i <= n; i ++){
		vector<int> pre(m + 1);
		for(int j = 1; j <= m; j ++){
			pre[j] = pre[j - 1] + (s[i][j] == '1');
		}
		int tot = count(s[i].begin() + 1, s[i].end(), '1');
		g[i].resize(tot + 1);
		fill(g[i].begin(), g[i].end(), 1e9);
		g[i][tot] = 0;
		for(int j = 1; j <= m; j ++){
			for(int k = j; k <= m; k ++){
				int cnt = pre[k] - pre[j - 1];
				g[i][tot - cnt] = min(g[i][tot - cnt], k - j + 1);
			}
		}
	}
	f[0][0] = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= k; j ++){
			for(int o = 0; o < g[i].size(); o ++){
				if(j - o < 0) continue;
				f[i][j] = min(f[i][j], f[i - 1][j - o] + g[i][o]);
			}
		}
	}
	cout << *min_element(f[n].begin(), f[n].end()) << '\n';
}
