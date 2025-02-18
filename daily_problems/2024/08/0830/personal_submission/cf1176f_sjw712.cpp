void solve(){
	int n;
	cin >> n;
	vector<int> f(10, -1e18), g(10, -1e18);
	f[0] = 0;
	while(n --){
		int k;
		cin >> k;
		vector<vector<int>> tmp(4);
		for(int i = 1; i <= k; i ++){
			int c, d;
			cin >> c >> d;
			tmp[c].push_back(d);
		}
		for(int i = 1; i <= 3; i ++){
			sort(tmp[i].begin(), tmp[i].end(), greater<int>());
		}
		for(int c1 = 0; c1 <= tmp[1].size() && c1 <= 3; c1 ++){
			for(int c2 = 0; c2 <= tmp[2].size() && c2 * 2 + c1 <= 3; c2 ++){
				for(int c3 = 0; c3 <= tmp[3].size() && c3 * 3 + c2 * 2 + c1 <= 3; c3 ++){
					int v = 0, mx = 0;
					for(int i = 0; i < c1; i ++){
						v += tmp[1][i];
						mx = max(tmp[1][i], mx);
					}
					for(int i = 0; i < c2; i ++){
						v += tmp[2][i];
						mx = max(tmp[2][i], mx);
					}
					for(int i = 0; i < c3; i ++){
						v += tmp[3][i];
						mx = max(tmp[3][i], mx);
					}
					
					for(int i = 0; i < 10; i ++){
						int tot = v + f[i];
						int cnt = c1 + c2 + c3 + i;
						if(cnt >= 10){
							tot += mx;
							cnt -= 10;
						}
						g[cnt] = max(g[cnt], tot);
					}
				}
			}
		}
		for(int i = 0; i < 10; i ++) f[i] = g[i], g[i] = -1e18;
	}
	cout << *max_element(f.begin(), f.end());
}
