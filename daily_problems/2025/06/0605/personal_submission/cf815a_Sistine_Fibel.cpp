void solve(){
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
	for(int i = 0; i < n + 1; i ++)
		a[i][0] = 0;
	for(int i = 0; i < n + 1; i ++)
		a[0][i] = 0;	
	vector<pair<string, int> > ans;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> a[i][j];
	
	if(m >= n){
		for(int i = 1; i <= n; i ++){
			int minx = INF;
			for(int j = 1; j <= m; j ++)
				minx = min(minx, a[i][j]);
			if(minx != 0){
				for(int j = 1; j <= m; j ++)
					a[i][j] -= minx;
				for(int k = 1; k <= minx; k ++)
					ans.push_back({"row", i});
			}
		}
		for(int j = 1; j <= m; j ++){
			int minx = INF;
			for(int i = 1; i <= n; i ++)
				minx = min(minx, a[i][j]);
			if(minx != 0){
				for(int i = 1; i <= n; i ++)
					a[i][j] -= minx;
				for(int k = 1; k <= minx; k ++)
					ans.push_back({"col", j});
			}
		}
	}
	else { //再来两遍喵
		for(int j = 1; j <= m; j ++){
			int minx = INF;
			for(int i = 1; i <= n; i ++)
				minx = min(minx, a[i][j]);
			if(minx != 0){
				for(int i = 1; i <= n; i ++)
					a[i][j] -= minx;
				for(int k = 1; k <= minx; k ++)
					ans.push_back({"col", j});
			}
		}
		for(int i = 1; i <= n; i ++){
			int minx = INF;
			for(int j = 1; j <= m; j ++)
				minx = min(minx, a[i][j]);
			if(minx != 0){
				for(int j = 1; j <= m; j ++)
					a[i][j] -= minx;
				for(int k = 1; k <= minx; k ++)
					ans.push_back({"row", i});
			}
		}
	}
		
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(a[i][j] != 0) {
				cout << -1;
				return;
			}
	cout << ans.size() << endl;
	for(auto [x, y] : ans){
		cout << x << " " << y << endl;
	}
}
