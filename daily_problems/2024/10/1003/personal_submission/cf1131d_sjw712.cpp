void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> s(n + 1);
	DSU dsu(n + m + 2);
	vector<vector<int>> adj(n + m + 1);
	vector<int> deg(n + m + 1), dist(n + m + 1);
	for(int i = 1; i <= n; i ++){
		cin >> s[i];
		s[i] = ' ' + s[i];
		for(int j = 1; j <= m; j ++){
			if(s[i][j] == '='){
				dsu.merge(i, j + n);
			}
		}
	}
	auto add = [&](int a, int b)->void{
		adj[a].push_back(b);
		deg[b] ++;
	};
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			int x = dsu.find(i), y = dsu.find(j + n);
			if(s[i][j] == '<'){
				add(x, y);
			}
			if(s[i][j] == '>'){
				add(y, x);
			}
		}
	}
	queue<int> q;
	int cnt = 0;
	for(int i = 1; i <= n + m; i ++){
		if(dsu.find(i) == i){
			if(!deg[i]){
				dist[i] = 1;
				q.push(i);
			}
			cnt ++;
		}
	}
	while(q.size()){
		auto u = q.front();
		q.pop();
		cnt --;
		for(auto v : adj[u]){
			dist[v] = max(dist[v], dist[u] + 1);
			deg[v] --;
			if(deg[v] == 0) q.push(v);
		}
	}
	if(cnt != 0) return cout << "NO" << '\n', void();
	cout << "YES" << '\n';
	for(int i = 1; i <= n + m; i ++){
		if(dsu.find(i) != i){
			dist[i] = dist[dsu.find(i)];
		}
	}
	for(int i = 1; i <= n; i ++) cout << dist[i] << " \n"[i == n];
	for(int i = n + 1; i <= n + m; i ++) cout << dist[i] << " \n"[i == n + m + 1];
}
