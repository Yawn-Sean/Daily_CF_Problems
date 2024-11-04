void solve(){
	int n;
	cin >> n;
	vector<int> a(n), ans;
	vector<bool> vis(n);
	for(int i = 0; i < n; i ++) cin >> a[i];
	vector<int> pre(n), suf(n);
	pre[0] = n - 1, suf[n - 1] = 0;
	for(int i = 1; i <= n - 1; i ++){
		pre[i] = i - 1;
		suf[i - 1] = i;
	}
	auto del = [&](int x)->void{
		int prex = pre[x], sufx = suf[x];
		pre[sufx] = prex;
		suf[prex] = sufx;
	};
	queue<int> q;
	for(int i = 0; i < n; i ++) q.push(i);
	while(q.size()){
		auto u = q.front();
		q.pop();
		if(vis[u]) continue;
		int v = suf[u];
		if(gcd(a[u], a[v]) == 1){
			ans.push_back(v + 1);
			vis[v] = true;
			del(v);
			q.push(u);
		}
	}
	cout << ans.size() << " ";
	for(auto i : ans) cout << i << " ";
	cout << '\n';
}
