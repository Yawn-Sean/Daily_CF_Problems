const int mod = 998244353;
void solve(){
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<int> a(q + 1), b(q + 1);
	vector<bool> vis1(n + 1), vis2(m + 1);
	for(int i = 1; i <= q; i ++){
		int x, y;
		cin >> x >> y;
		a[i] = x, b[i] = y;
	}
	int ans = 1, c1 = 0, c2 = 0;
	for(int i = q; i >= 1; i --){
		if(!vis1[a[i]] && c1 != m || !vis2[b[i]] && c2 != n){
			ans = ans * k % mod;
			if(!vis2[b[i]]) vis2[b[i]] = true, c1 ++;
			if(!vis1[a[i]]) vis1[a[i]] = true, c2 ++;
		}
	}
	cout << ans << '\n';
}
