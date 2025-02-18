void solve(){
	int n;
	cin >> n;
	int k = 0;
	while((1 << k) < n) k ++;
	vector<vector<int>> f(n, vector<int>(k)), g(n, vector<int>(k));
	auto query = [&](vector<int> tmp)->vector<int>{
		vector<int> res;
		cout << tmp.size() << endl;
		for(int i = 0; i < tmp.size(); i ++){
			cout << tmp[i] << " ";
		}
		cout << endl;
		for(int i = 0; i < n; i ++){
			int x;
			cin >> x;
			res.push_back(x);
		}
		return res;
	};
	for(int bit = 0; bit < k; bit ++){
		vector<int> tmp;
		for(int i = 1; i <= n; i ++){
			if(i >> bit & 1) tmp.push_back(i);
		}
		auto res = query(tmp);
		for(int i = 0; i < n; i ++) f[i][bit] = res[i];
		tmp.clear();
		for(int i = 1; i <= n; i ++){
			if(!(i >> bit & 1)) tmp.push_back(i);
		}
		res = query(tmp);
		for(int i = 0; i < n; i ++) g[i][bit] = res[i];
	}
	cout << -1 << endl;
	for(int i = 0; i < n; i ++){
		int res = 1e18;
		for(int bit = 0; bit < k; bit ++){
			if((i + 1) >> bit & 1) res = min(res, g[i][bit]);
			else res = min(res, f[i][bit]);
		}
		cout << res << " ";
	}
	cout << endl;
}
