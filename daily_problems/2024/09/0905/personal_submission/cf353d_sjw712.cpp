void solve(){
	string s;
	cin >> s;
	int ans = 0, cur = 0;
	for(int i = 0; i < s.size(); i ++){
		if(s[i] == 'M') cur ++;
		else if(cur > 0) ans = max(ans + 1, cur);
	}
	cout << ans << '\n';
}
