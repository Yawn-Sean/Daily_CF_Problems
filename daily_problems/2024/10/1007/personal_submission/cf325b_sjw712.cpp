void solve(){
	int n;
	cin >> n;
	vector<int> ans;
	for(int k = 0; k <= 61; k ++){
		auto get = [&](int x)->int{
			if((1ll << k) - 1 > (n - x * (x - 1) / 2) / x + 1) return 9e18;
			return ((1ll << k) - 1) * x + x * (x - 1) / 2;
		};

		int l = 1, r = 1e9;
		while(l < r){
			int mid = l + r + 1 >> 1;
			if(get(2 * mid - 1) <= n) l = mid;
			else r = mid - 1;
		}
		if(get(l * 2 - 1) == n) ans.push_back((1ll << k) * (2 * l - 1));
	}
	sort(ans.begin(), ans.end());
	if(ans.size() == 0) cout << -1 << '\n';
	else{
		for(auto i : ans) cout << i << " ";
	}
}
