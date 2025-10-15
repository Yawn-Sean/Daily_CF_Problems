void solve(){
    using gint = Graph;

    int n, m, ma = 0;
    cin >> n >> m;
    vector<array<int,3>> edgs;
    const int sr = 2*n, sk = 2*n+1;

    for (int i = 0,u,v,d; i < m; ++ i){
        cin >> u >> v >> d;
        u -= 1, v -= 1;
        v += n;
        edgs.push_back({u, v, d});
        fmax(ma, d);
    }

    auto chk = [&](int mid)->bool{
        gint G(2*n+2);
        G.set(sr, sk);
        for (int i = 0; i < n; ++ i){
            G.add(sr, i, 1);
        }
        for (int i = n; i < 2*n; ++ i){
            G.add(i, sk, 1);
        }
        for (int i = 0; i < m; ++ i){
            auto &[u, v, d] = edgs[i];
            if (d > mid) continue;
            G.add(u, v, 1);
        }

        return G.dinic() == n;
    };

    int lo = 1, hi = ma;
    while (lo < hi){
        int mid = (lo+hi) >> 1;
        if (chk(mid)) hi = mid;
        else lo = mid+1;
    }

    if (chk(lo)) cout << lo << "\n";
    else cout << -1 << "\n";
}
