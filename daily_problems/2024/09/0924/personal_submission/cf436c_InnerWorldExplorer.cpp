struct Edge {
	int u, v, w;
	bool operator<(const Edge& other) { return w < other.w; }
};

int fa[1010];

int cnt;
Edge g[1001010];

void add(int u, int v, int w) {
	cnt ++;
	g[cnt].u = u;
	g[cnt].v = v;
	g[cnt].w = w;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	vector<vector<string>> dungeons(k, vector<string>(n));
	for (int i = 0; i < k; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> dungeons[i][j];
		}
	}
	for (int i = 1; i <= k; i ++) {
		add(i, 0, n * m);
		for (int j = 1; j < i; j ++) {
			int cost = 0;
			for (int x = 0; x < n; x ++) {
				for (int y = 0; y < m; y ++) {
					if (dungeons[i - 1][x][y] != dungeons[j - 1][x][y]) {
						cost += w;
					}
				}
			}
			add(i, j, cost);
		}
	}
	for (int i = 1; i <= k; i++) {
		fa[i] = i;
	}
	vector<Edge> path;
	sort(g + 1, g + cnt + 1);
	int cost = 0;
	for (int i = 1; i <= cnt; i ++) {
		if (find(g[i].u) != find(g[i].v)) {
			merge(g[i].u, g[i].v);
			path.push_back(g[i]);
			cost += g[i].w;
		}
	}
	cout << cost << endl;
	int sz = (int)path.size();
	vector<bool> vis(sz);
	auto dfs = [&](auto && self, int root) -> void{
		for (int i = 0; i < sz; i ++) {
			if (vis[i]) continue;
			if (path[i].v == root) {
				cout << path[i].u << " " << path[i].v << endl;
				vis[i] = true;
				self(self, path[i].u);
			}
			if (path[i].u == root) {
				cout << path[i].v << " " << path[i].u << endl;
				vis[i] = true;
				self(self, path[i].v);
			}
		}
	};
	dfs(dfs, 0);
	return 0;
}
