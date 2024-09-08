void solve(){
	int n;
	cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; i ++) cin >> s[i];
	unordered_map<string, string> mp;
	unordered_map<string, string> ans;
	unordered_map<string, int> cnt;
	vector<string> v;
	auto work = [&](string s)->void{
		unordered_set<string> se;
		for(int len = 1; len <= 9; len ++){
			for(int i = 0; i < 9; i ++){
				if(i + len - 1 < 9){
					string t = s.substr(i, len);
					se.insert(t);
				}
			}
		}
		for(auto t : se){
			if(!cnt.count(t)) cnt[t] = 1, mp[t] = s;
			else cnt[t] = 0;
		}
	};
	for(int i = 0; i < n; i ++){
		work(s[i]);
	}
	for(auto &[t, c] : cnt){
		if(c == 1) v.push_back(t);
	}
	sort(v.begin(), v.end(), [](string s, string t){
		return s.size() < t.size();
	});
	for(auto t : v){
		if(!ans.count(mp[t])){
			ans[mp[t]] = t;
		}
		if(ans.size() == n) break;
	}
	for(int i = 0; i < n; i ++){
		cout << ans[s[i]] << '\n';
	}
}
