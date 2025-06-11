void solve(){
	int a, b, mod;
	cin >> a >> b >> mod;
	if(b >= mod) return cout << 2 << '\n', void();
	for(int i = 1; i <= min(a, mod); i ++){
		if((mod - i * (1000000000 % mod) % mod) % mod > b){
			cout << 1 << " ";
			string ans = to_string(i);
			int len = ans.size();
			for(int j = 0; j < 9 - len; j ++) ans = '0' + ans;
			cout << ans << '\n';
			return;
		}
	}
	cout << 2 << '\n';
}
