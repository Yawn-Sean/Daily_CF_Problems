void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1), pre(n + 1), suf(n + 1), b(n + 1), c(n + 1);
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 1e18;
	int last = a[1];
	b[1] = c[1] = a[1], b[n] = c[n] = a[n];
	for(int i = 2; i <= n; i ++){
		pre[i] = pre[i - 1];
		if(a[i] <= last){
			pre[i] += last + 1 - a[i];
			last += 1;
		}
		else{
			last = a[i];
		}
		b[i] = last;
	}
	last = a[n];
	for(int i = n - 1; i >= 1; i --){
		suf[i] = suf[i + 1];
		if(a[i] <= last){
			suf[i] += last + 1 - a[i];
			last += 1;
		}
		else{
			last = a[i];
		}
		c[i] = last;
	}
	for(int i = 2; i <= n - 1; i ++){
		ans = min(ans, pre[i - 1] + suf[i + 1] + (a[i] > max(b[i - 1], c[i + 1]) ? 0 : max(b[i - 1], c[i + 1]) + 1 - a[i]));
	}
	ans = min({ans, pre[n], suf[1]});
	cout << ans << '\n';
}
