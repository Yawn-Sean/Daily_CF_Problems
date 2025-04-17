void solve(){
    int n, x;
    cin >> n >> x;
    x -= 1;
    vector<vector<int>> g(n);
    vector <int> dep(n), dist(n, -1);
    for (int i = 0,u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <array<int,2>> stk = {{0, -1}};
    while (!stk.empty()){
        auto [u, presor] = stk.back();
        stk.pop_back();
        for (auto &v : g[u]){
            if (v == presor) continue;
            dep[v] = dep[u] + 1;
            stk.push_back({v, u});
        }
    }

    queue <int> Q;
    Q.push(x);
    dist[x] = 0;
    while (!Q.empty()){
        auto u = Q.front();
        Q.pop();
        for (auto &v : g[u]){
            if (dist[v] != -1 || v == 0) continue;
            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++ i){
        if (dist[i] != -1 && dep[i] > dist[i]){
            fmax(res, dep[i]);
        }
    }
    cout << 2*res << "\n";
}
