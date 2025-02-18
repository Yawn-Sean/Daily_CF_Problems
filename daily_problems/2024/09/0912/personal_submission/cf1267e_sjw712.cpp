void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			cin >> a[j][i];
		}
	}
	int sum = 0, mx = 1e9;
	vector<int> res;
	for(int i = 1; i <= m; i ++) sum += a[n][i];
	auto work = [&](int x)->void{
		vector<pii> d(m + 1);
		int cnt = 0;
		vector<int> ans;
		int sumx = accumulate(a[x].begin() + 1, a[x].end(), 0);
		for(int i = 1; i <= m; i ++){
			d[i] = {a[x][i] - a[n][i], i};
		}
		sort(d.begin() + 1, d.end());
		bool ok = false;
		for(int i = 1; i <= n; i ++){
			if(sumx >= sum){
				ok = true;
				break;
			}
			sumx -= d[i].x;
			cnt ++;
			ans.push_back(d[i].y);
		}
		if(sumx >= sum || ok){
			if(cnt < mx){
				mx = cnt;
				res = ans;
			}
		}
	};
	for(int i = 1; i <= n - 1; i ++){
		work(i);
	}
	cout << res.size() << '\n';
	for(auto i : res) cout << i << " ";
}
