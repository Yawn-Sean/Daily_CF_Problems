//https://codeforces.com/contest/567/submission/258305512
void solve() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--;
	t--;
	vector<vector<array<int,3>>> son(n), pa(n);

	vector<array<int,3>> roads(m);
	for (int i = 0; i < m; i++){
		int u, v, w; cin >> u >> v >> w;
		u--; v--;
		son[u].push_back({v, w, i});
		pa[v].push_back({u, w, i});
		roads[i] = {u, v, w};
	}
	const i64 INF = 1LL << 60;
	//distance and # of paths from source
	vector<i64> sDist(n, INF), tDist(n, INF);
	vector<Z> sPath(n, 0), tPath(n, 0);

	auto gao = [&](int source, vector<vector<array<int,3>>> &adj, vector<i64> &dist, vector<Z> &path) -> void {
		dist[source] = 0;
		path[source] = Z(1);
		vector<int> visited(n, 0);
		priority_queue<array<i64,2>, vector<array<i64,2>>, greater<array<i64,2>>> pq;
		pq.push({0, source});
		while(!pq.empty()){
			auto [d, u] = pq.top(); pq.pop();
			if (visited[u]) continue;
			visited[u] = 1;
			for (auto &[v, w, idx] : adj[u]){
				i64 newDist = dist[u] + w;
				if (dist[v] > newDist){
					dist[v] = newDist;
					path[v] = path[u];
					pq.push({dist[v], v});
				}
				else if (dist[v] == newDist){
					path[v] += path[u];
				}
			}
		}
	};
	gao(s, son, sDist, sPath);
	gao(t, pa, tDist, tPath);

	auto minST = sDist[t];

	for (auto &[u, v, w] : roads){
		//check if the path is among one of the shortest path
		if (sDist[u] + w + tDist[v] == minST){
			//on shortest path
			if ((sPath[u] * tPath[v] - sPath[t]).val() == 0){
				cout << "YES\n";
			}
			else {
				if (w > 1){
					cout << "CAN 1\n";
				}
				else cout << "NO\n";
			}
		}
		else {
			//not on shortest path
			i64 goal = minST - 1 - sDist[u] - tDist[v];
			if (goal <= 0){
				cout << "NO\n";
			}
			else cout << "CAN " << w - goal << "\n";
		}
	}
}
