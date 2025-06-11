void solve(){
	string s;
	cin >> s;
	s = ' ' + s;
	int n = s.size();
	vector<vector<int>> cnt(26, vector<int>(n));
	for(int i = 1; i < n; i ++){
		for(int j = 0; j < 26; j ++){
			cnt[j][i] = cnt[j][i - 1] + (s[i] == 'a' + j);
		}
	}
	int q;
	cin >> q;
	while(q --){
		int l, r;
		cin >> l >> r;
		if(l == r){
			cout << "Yes" << '\n';
			continue;
		}
		int res = 0;
		for(char c = 'a'; c <= 'z'; c ++){
			if(cnt[c - 'a'][r] - cnt[c - 'a'][l - 1]){
				res ++;
			}
		}
		if(res <= 2 && l != r && s[l] == s[r]) cout << "No" << '\n';
		else cout << "Yes" << '\n';
	}
}
