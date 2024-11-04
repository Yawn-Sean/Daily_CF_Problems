void solve(){
	int n, k;
	cin >> n >> k;
	vector<string> s(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	dp[1][1] = (s[1][1] != 'a');
	for(int i = 2; i <= n; i ++) dp[1][i] = dp[1][i - 1] + (s[1][i] != 'a');
	for(int i = 2; i <= n; i ++) dp[i][1] = dp[i - 1][1] + (s[i][1] != 'a');
	for(int i = 2; i <= n; i ++){
		for(int j = 2; j <= n; j ++){
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + (s[i][j] != 'a');
		}
	}
	int mx = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			if(dp[i][j] <= k){
				if(i + j > mx){
					mx = i + j;
				}
			}
		}
	}
	vector<pii> tmp;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			if(dp[i][j] <= k && i + j == mx){
				tmp.push_back({i, j});
			}
		}
	}
	for(int i = 1; i <= mx - 1; i ++) cout << 'a';
	if(tmp.size() == 0){
		tmp.push_back({1, 1});
		cout << s[1][1];
		mx = 2;
	}
	vector<pii> dirs = {{1, 0}, {0, 1}};
	for(int i = mx; i <= 2 * n - 1; i ++){
		char nxt = 'z' + 1;
		vector<pii> ntmp;
		for(auto &[x, y] : tmp){
			for(auto &[dx, dy] : dirs){
				int nx = x + dx, ny = y + dy;
				if(nx <= n && ny <= n && s[nx][ny] < nxt){
					nxt = s[nx][ny];
				}
			}
		}
		for(auto &[x, y] : tmp){
			for(auto &[dx, dy] : dirs){
				int nx = x + dx, ny = y + dy;
				if(nx <= n && ny <= n && s[nx][ny] == nxt){
					ntmp.push_back({nx, ny});
				}
			}
		}
		sort(ntmp.begin(), ntmp.end());
		ntmp.erase(unique(ntmp.begin(), ntmp.end()), ntmp.end());
		ntmp.swap(tmp);
		cout << nxt;
	}
}
