void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) cin >> a[i];
	vector<vector<int>> ans;	
	int j = 0;
	for(int i = 0; i < n; i ++){
		int l = 0, r = ans.size();
		while(l < r){
			int mid = l + r >> 1;
			if(ans[mid].back() < a[i]) r = mid;
			else l = mid + 1;
		}
		if(l == ans.size()) ans.push_back({a[i]});
		else ans[l].push_back(a[i]);
	}
	for(int i = 0; i < ans.size(); i ++){
		for(int j = 0; j < ans[i].size(); j ++){
			cout << ans[i][j] << " ";
		}
		cout << '\n';
	}
}
