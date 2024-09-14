const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], w[M], idx;
int a[N], dist[N], sz[N];
int ans;
void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}
void dfs1(int u, int fa){
	sz[u] = 1;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(j == fa) continue;
		dist[j] = dist[u] + w[i];
		dfs1(j, u);
		sz[u] += sz[j];
	}
}
void dfs2(int u, int fa, int sum, int mn){
	if(dist[u] - mn > a[u]) {
		ans += sz[u];
		return;
	}
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(j == fa) continue;
		dfs2(j, u, sum + w[i], min(mn, sum + w[i]));
	}
}
void solve(){
	int n;
	cin >> n;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n - 1; i ++){
		int p, c;
		cin >> p >> c;
		add(i + 1, p, c);
		add(p, i + 1, c);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0, 0);
	cout << ans << '\n';
}
