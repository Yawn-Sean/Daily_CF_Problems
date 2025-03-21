void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector <int> color(n), degs(n);
    for (auto &x : color){
        cin >> x;
    }
    for (int i = 0,u,v; i < m; ++ i){
        cin >> u >> v;
        g[v].push_back(u);
        degs[u] += 1;
    }
    vector<queue<int>> Q(2);
    for (int i = 0; i < n; ++ i){
        if (!degs[i]){
            Q[color[i]].push(i);
        }
    }
    int res = 0;

    while (!Q[0].empty() || !Q[1].empty()){
        while (!Q[0].empty()){
            int u = Q[0].front();
            Q[0].pop();
            for (auto &v : g[u]){
                -- degs[v];
                if (degs[v] == 0){
                    Q[color[v]].push(v);
                }
            }
        }
        if (!Q[1].empty()){
            res += 1;
            while (!Q[1].empty()){
                int u = Q[1].front();
                Q[1].pop();
                for (auto &v : g[u]){
                    -- degs[v];
                    if (degs[v] == 0){
                        Q[color[v]].push(v);
                    }
                }
            }
        }
    }

    cout << res << "\n";
}
