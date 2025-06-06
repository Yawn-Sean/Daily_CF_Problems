void solve(){
    int n, m, k, sr, sk;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    vector <int> p(n), color(n, -1), ones, dist(n, inf_int);  // color 用于给点染色

    iota(p.begin(), p.end(), 0);  // 并查集初始化
    auto find = [&](int x)->int{
        int y = x;
        while (p[y] != y){
            y = p[y];
        }
        while (p[x] != x){
            int &j = p[x];
            x = p[x];
            j = y;
        }
        return y;
    };
    auto merge = [&](int x, int y)->void{
        x = find(x), y = find(y);
        if (x == y) return;
        p[y] = x;
    };

    for (int i = 0, x; i < k; ++ i){
        cin >> x;
        x -= 1;
        color[x] = x, dist[x] = 0;
        ones.push_back(x);
    }
    for (int i = 0,u,v; i < m; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> sr >> sk;
    sr -= 1, sk -= 1;
    color[sr] = sr, color[sk] = sk;
    dist[sr] = 0, dist[sk] = 0;

    int lp = 0, rp = -1;
    vector <int> Q(2*n);
    for (auto &x : ones){
        Q[++ rp] = x;
    }
    Q[++ rp] = sk;

    int res = inf_int, anchor = rp, jg = 0;
    vector <array<int,3>> egs;
    for (int i = 1; i <= n-1; ++ i){
        while (lp <= anchor){
            int u = Q[lp++];
            for (auto &v : g[u]){
                if (color[u] == color[v]) continue;
                if (color[v] == -1){
                    color[v] = color[u];
                    dist[v] = dist[u]+1;
                    assert(dist[v] == i);
                    Q[++ rp] = v;
                } else {
                    egs.push_back({color[u], color[v], dist[u]+dist[v]+1});
                }
            }
        }
        anchor = rp;
    }
    sort(egs.begin(), egs.end(), [&](auto &u, auto &v){
        return u[2] < v[2];
    });
    for (auto [u, v, c] : egs){
        merge(u, v);
        if (find(sr) == find(sk)){
            res = c;
            jg = 1;
            break;
        }
    }

    if (jg) cout << res << "\n";
    else cout << -1 << "\n";
}
