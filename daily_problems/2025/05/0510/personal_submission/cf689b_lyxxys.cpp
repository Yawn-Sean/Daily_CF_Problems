void solve(){
    int n;
    cin >> n;
    vector <int> dist(n, inf_int);
    vector<vector<int>> g(n);
    for (int i = 0, v; i < n; ++ i){
        cin >> v;
        v -= 1;
        if (v > i){
            g[i].push_back(v);
        }
    }
    for (int i = 0; i < n-1; ++ i){
        g[i].push_back(i+1);
    }
    for (int i = n-1; i > 0; -- i){
        g[i].push_back(i-1);
    }

    queue <int> Q;
    dist[0] = 0;
    Q.push(0);

    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for (auto &v : g[u]){
            if (dist[v] > dist[u]+1){
                dist[v] = dist[u]+1;
                Q.push(v);
            }
        }
    }

    print(dist);
}
