void solve(){
	int n, x, k;
	cin >> n >> x >> k;
	vector<int> a(n), pre(n);
	for(int i = 0; i < n; i ++) cin >> a[i];
	sort(a.begin(), a.end());
	for(int i = 1; i < n; i ++){
		if(a[i] == a[i - 1]){
			pre[i] = pre[i - 1];
		}
		else pre[i] = i;
	}
	int ans = 0;
	auto check = [&](int i, int j)->int{
		int l = (a[i] + x - 1) / x * x;
		int r = a[j] / x * x;
		return max(0ll, (r - l) / x + 1);
	};
	for(int i = 0; i < n; i ++){
		int l1 = pre[i], r1 = n - 1;
		while(l1 < r1){
			int mid = l1 + r1 >> 1;
			if(check(pre[i], mid) >= k) r1 = mid;
			else l1 = mid + 1;
		}
		int l2 = pre[i], r2 = n - 1;
		while(l2 < r2){
			int mid = l2 + r2 + 1 >> 1;
			if(check(pre[i], mid) <= k) l2 = mid;
			else r2 = mid - 1;
		}
		if(check(pre[i], l1) == k) ans += l2 - l1 + 1; 
	}
	cout << ans << '\n';
}
