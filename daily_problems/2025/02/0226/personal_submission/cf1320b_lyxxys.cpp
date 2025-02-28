void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector <int> dist(n, inf_int), f(n);
    for (int i = 0,u,v; i < m; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[v].push_back(u);
    }
    int k;
    cin >> k;
    vector <int> p(k);
    for (auto &x : p){
        cin >> x;
        x -= 1;
    }

    const int S = p[k-1];
    priority_queue <array<int,2>,vector<array<int,2>>,greater<>> pq;
    dist[S] = 0, pq.push({0, S}), f[S] = 1;
    while (!pq.empty()){
        auto [odis, u] = pq.top();
        pq.pop();
        if (odis > dist[u]) continue;
        for (auto &v : g[u]){
            if (dist[v] > dist[u]+1){
                dist[v] = dist[u]+1;
                f[v] = 1;
                pq.push({dist[v], v});
            } else if (dist[v] == dist[u]+1){
                f[v] = 2;
            }
        }
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 1; i < k; ++ i){
        int u = p[i-1], v = p[i];
        if (dist[u] != dist[v]+1){
            ans1 += 1, ans2 += 1;
        } else if (f[u] > 1){
            ans2 += 1;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
}
