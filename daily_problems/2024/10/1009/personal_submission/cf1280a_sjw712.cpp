void solve(){
	int n, x;
	string s;
	cin >> x >> s;
	n = s.size();
	int ans = n;
	for(int i = 0; i < x; i ++){
		int t = s[i] - '0' - 1;
		ans = (ans + ((ans - i - 1) * t + mod) % mod) % mod;
		if(s.size() < x){
			string c = s.substr(i + 1);
			for(int j = 1; j <= t; j ++){
				if(s.size() < x){
					if(s.size() + c.size() >= x){
						c = c.substr(0, x - s.size());
					}
					s += c;
				}
				else{
					break;
				}
			}
		}
	}
	cout << ans << '\n';
}
