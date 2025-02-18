void solve(){
	int m;
	cin >> m;
	int l = 1, r = 1e18;
	auto check = [&](int x)->int{
		int cnt = 0;
		for(int q = 2; q <= x / q / q; q ++){
			cnt += x / q / q / q;
		}
		return cnt;
	};
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid) >= m) r = mid;
		else l = mid + 1;
	}
	int cnt = check(l);
	if(cnt == m) cout << l << '\n';
	else cout << -1 << '\n';
}
