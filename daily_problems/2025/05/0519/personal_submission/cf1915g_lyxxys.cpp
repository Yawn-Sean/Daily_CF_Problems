void solve(){
    using ary2 = array<i64,2>;

    int n, m;
    cin >> n >> m;
    vector<vector<i64>> f(n,vector<i64>(n, inf_i64));
    vector<vector<int>> g(n);
    vector<array<int,2>> edges;
    vector <int> A(n);
    for (int i = 0,u,v,w; i < m; ++ i){
        cin >> u >> v >> w;
        u -= 1, v -= 1;
        edges.push_back({u+v, w});
        g[u].push_back(i);
        g[v].push_back(i);
    }
    for (auto &x : A){
        cin >> x;
    }
    priority_queue <ary2,vector<ary2>,greater<ary2>> pq;
    auto cover = [&](int i, int j)->int{
        return i*n + j;
    };
    auto fix = [&](int x)->array<int,2>{
        return {x/n, x%n};
    };
    f[0][0] = 0;
    pq.push({0, cover(0, 0)});

    while (!pq.empty()){
        auto [odis, id] = pq.top();
        pq.pop();
        auto [i, j] = fix(id);
        if (f[i][j] > odis) continue;

        if (i != j && A[i] < A[j] && f[i][i] > f[i][j]){
            f[i][i] = f[i][j];
            pq.push({f[i][j], cover(i, i)});
        }

        for (auto &id : g[i]){
            int iu = edges[id][0]-i, w = edges[id][1];
            if (f[iu][j] > f[i][j] + w*A[j]){
                f[iu][j] = f[i][j] + w*A[j];
                pq.push({f[iu][j], cover(iu, j)});
            }
        }
    }
    // return;
    i64 res = inf_i64;
    for (int i = 0; i < n; ++ i){
        fmin(res, f[n-1][i]);
    }
    cout << res << "\n";
}
