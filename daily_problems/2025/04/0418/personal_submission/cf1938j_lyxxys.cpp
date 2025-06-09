void solve(){
    using ary2 = array<i64,2>;

    int n, m;
    cin >> n >> m;
    vector <i64> f(n, inf_i64), t(n, inf_i64);
    vector <u64> ins(n);
    vector<vector<int>> g(n);
    vector<vector<ary2>> pre(n);
    vector<array<int,3>> edges;
    for (int i = 0,u,v,w; i < m; ++ i){
        cin >> u >> v >> w;
        u -= 1, v -= 1;
        edges.push_back({u, v, w});
        g[u].push_back(i);
        g[v].push_back(i);
    }

    f[0] = 0;
    priority_queue<ary2, vector<ary2>, greater<ary2>> pq;
    pq.push({0, 0});
    while (!pq.empty()){
        auto [dis, u] = pq.top();
        pq.pop();

        if (f[u] == dis){
            for (auto &id : g[u]){
                int v = edges[id][0]+edges[id][1]-u, w = edges[id][2];
                if (f[v] > f[u]+w){
                    pre[v].clear();
                    pre[v].push_back({u, id});
                    f[v] = f[u]+w;
                    pq.push({f[v], v});
                    ins[v] = ins[u];
                } else if (f[v] == f[u]+w){
                    ins[v] += ins[u];
                    // pre[v].push_back({u, id});
                }
            }
        }
    }

    t[n-1] = 0;
    pq.push({0, n-1});
    while (!pq.empty()){
        auto [dis, u] = pq.top();
        pq.pop();
        if (t[u] == dis){
            for (auto &id : g[u]){
                int v = edges[id][0]+edges[id][1]-u, w = edges[id][2];
                if (t[v] > t[u]+w){
                    t[v] = t[u]+w;
                    pq.push({t[v], v});
                }
            }
        }
    }

    if (f[n-1] == inf_i64) return void(cout << -1 << "\n");

    // if (ins[n-1] > 1){
    //     cout << 2*f[n-1] << "\n";
    //     return;
    // }

    vector <int> vis(n), used(m);
    queue <int> Q;
    Q.push(n-1);
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto &[v, id] : pre[u]){
            if (vis[v]) continue;
            used[id] = 1;
            Q.push(v);
        }
    }

    i64 res = inf_i64;
    for (int i = 0; i < m; ++ i){
        if (used[i]) continue;
        auto [u, v, w] = edges[i];
        fmin(res, f[u]+t[v]+w);
        fmin(res, f[v]+t[u]+w);
    }

    if (res == inf_i64) return void(cout << -1 << "\n");

    cout << res+f[n-1] << "\n";
}
