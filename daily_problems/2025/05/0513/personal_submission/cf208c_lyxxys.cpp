void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < m; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto bfs = [&](int s, vector <i64> &f, vector <int> &dist)->void{
        fill(dist.begin(), dist.end(), inf_int);
        dist[s] = 0, f[s] = 1;
        queue <int> Q;
        Q.push(s);

        while (!Q.empty()){
            auto u = Q.front();
            Q.pop();

            for (auto &v : g[u]){
                if (dist[v] > dist[u]+1){
                    dist[v] = dist[u]+1;
                    f[v] = f[u];
                    Q.push(v);
                } else if (dist[v] == dist[u]+1){
                    f[v] += f[u];
                }
            }
        }
    };

    vector <i64> f1(n), f2(n);
    vector <int> dist1(n), dist2(n);
    bfs(0, f1, dist1);
    bfs(n-1, f2, dist2);

    int d = dist1[n-1];

    i64 res = f1[n-1];
    for (int i = 1; i < n-1; ++ i){
        if (dist1[i]+dist2[i] == d){
            fmax(res, 2*f1[i]*f2[i]);
        }
    }

    cout << fixed << setprecision(10) << 1.0 * res / f1[n-1] << "\n";
}
