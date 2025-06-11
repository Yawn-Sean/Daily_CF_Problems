struct Edge{
	int a, b, c;
	bool operator<(const Edge& t) const{
		return c < t.c;
	}
}edge[1000010];
void solve(){
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	vector<string> s(k + 1);
	s[0] = string(n * m, '#');
	for(int i = 1; i <= k; i ++){
		string t = "";
		for(int j = 1; j <= n; j ++){
			string ss;
			cin >> ss;
			t += ss;
		}
		s[i] = t;
	}
	auto get = [&](string a, string b)->int{
		int res = 0;
		for(int i = 0; i < a.size(); i ++){
			if(a[i] != b[i]) res ++;
		}
		return res;
	};
	int idx = 0;
	for(int i = 0; i <= k; i ++){
		for(int j = i + 1; j <= k; j ++){
			if(i != 0) edge[++ idx] = {i, j, get(s[i], s[j]) * w};
			else edge[++ idx] = {i, j, n * m};
		}	
	}
	sort(edge + 1, edge + 1 + idx);
	vector<int> fa(k + 1);
	iota(fa.begin(), fa.end(), 0);
	function<int(int)> find = [&](int x)->int{
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	};
	int cost = 0;
	vector<vector<int>> adj(k + 1);
	for(int i = 1; i <= idx; i ++){
		int a = edge[i].a, b = edge[i].b;
		int pa = find(a), pb = find(b);
		if(pa == pb) continue;
		cost += edge[i].c;
		fa[pb] = pa;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	
	cout << cost << '\n';
	auto dfs = [&](auto self, int u, int fa)->void{
		if(u) cout << u << " " << fa << '\n';
		for(auto j : adj[u]){
			if(j == fa) continue;
			self(self, j, u);
		}
	};
	dfs(dfs, 0, -1);
}
