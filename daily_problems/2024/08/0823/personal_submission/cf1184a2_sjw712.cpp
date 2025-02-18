void solve(){
	int n, ans = 0;
	cin >> n;
	string s;
	cin >> s;
	vector<bool> check(n + 1);
	for(int i = 1; i <= n; i ++){
		if(n % i == 0){
			vector<int> cnt(i);
			bool ok = true;
			for(int j = 0; j < s.size(); j ++){
				cnt[j % i] ^= s[j] - '0';
			}
			for(int j = 0; j < i; j ++){
				if(cnt[j]){
					ok = false;
					break;
				}
			}
			check[i] = ok;
		}
	}
	for(int i = 1; i <= n; i ++){
		ans += check[gcd(n, i)];
	}
	cout << ans << '\n';
}
