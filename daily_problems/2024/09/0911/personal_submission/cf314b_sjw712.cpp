void solve(){
	int b, d;
	string a, c;
	cin >> b >> d >> a >> c;
	vector<int> cnt(c.size() + 1), nxt(c.size() + 1);
	for(int i = 0; i < c.size(); i ++){
		int x = i;
		for(int j = 0; j < a.size(); j ++){
			if(a[j] == c[x]) x ++;
			if(x == c.size()) cnt[i] ++, x = 0;
		}
		nxt[i] = x;
	}
	int x = 0, ans = 0;
	for(int i = 1; i <= b; i ++){
		ans += cnt[x];
		x = nxt[x];
	}
	cout << ans / d << '\n';
}
