void solve(){
	int n, T;
	cin >> n >> T;
	map<int, vector<pii>> mp;
	for(int i = 1; i <= n; i ++){
		int a, t;
		cin >> a >> t;
		mp[t].push_back({a, i});
	}
	for(auto &[t, a] : mp){
		sort(a.begin(), a.end());
	}
	auto check = [&](int k)->bool{
		int sum = 0, cnt = 0;
		for(auto &[t, a] : mp){
			int x = lower_bound(a.begin(), a.end(), make_pair(k, 0ll)) - a.begin();
			for(int i = x; i < a.size(); i ++){
				if(sum + t > T) break;
				sum += t;
				cnt ++;
			}
		}
		return cnt >= k;
	};
	int l = 0, r = n;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
	cout << l << '\n';
	vector<int> ans;
	int sum = 0, cnt = 0;
	for(auto &[t, a] : mp){
		int x = lower_bound(a.begin(), a.end(), make_pair(l, 0ll)) - a.begin();
		for(int i = x; i < a.size(); i ++){
			if(sum + t > T) break;
			if(cnt == l) break;
			sum += t;
			cnt ++;
			ans.push_back(a[i].y);
		}
	}
	for(auto i : ans) cout << i << " ";
}
