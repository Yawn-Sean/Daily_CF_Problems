void solve(){
	int n, x, y, dx = 0, dy = 0;
	string s;
	cin >> n >> s >> x >> y;
	s = ' ' + s;
	vector<int> preu(n + 1), pred(n + 1), prel(n + 1), prer(n + 1);
	for(int i = 1; i <= n; i ++){
		preu[i] = preu[i - 1];
		pred[i] = pred[i - 1];
		prel[i] = prel[i - 1];
		prer[i] = prer[i - 1];
		if(s[i] == 'U') preu[i] ++, dy ++;
		if(s[i] == 'D') pred[i] ++, dy --;
		if(s[i] == 'L') prel[i] ++, dx --;
		if(s[i] == 'R') prer[i] ++, dx ++;
	}
	if(dx == x && dy == y) return cout << 0 << '\n', void();
	int ans = 1e9;
	auto check = [&](int l, int r)->bool{
		int cl = prel[n] - prel[r] + prel[l - 1];
		int cr = prer[n] - prer[r] + prer[l - 1];
		int cu = preu[n] - preu[r] + preu[l - 1];
		int cd = pred[n] - pred[r] + pred[l - 1];
		int nx = abs(x - cr + cl), ny = abs(y - cu + cd);
		int z = (r - l + 1) - (nx + ny);
		return z >= 0 && z % 2 == 0;
	};
	for(int i = 1; i <= n; i ++){
		int l = i, r = n + 1;
		while(l < r){
			int mid = l + r >> 1;
			if(check(i, mid)) r = mid;
			else l = mid + 1;
		}
		if(l != n + 1) ans = min(ans, l - i + 1);
	}
	if(ans == 1e9) ans = -1;
	cout << ans << '\n';
}
