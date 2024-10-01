void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++) cin >> b[i];
	vector<int> adj(n + 1);
	vector<bool> vis(n + 1);
	for(int i = 0; i < n; i ++) adj[a[i]] = b[i];
	int k = 0;
	for(int i = 1; i <= n; i ++){
		if(!vis[i]){
			int cnt = 0;
			while(!vis[i]){
				cnt ++;
				vis[i] = true;
				i = adj[i];
			}
			k += cnt / 2;
		}
	}
	cout << 2 * k * (n - k) << '\n';
}	
