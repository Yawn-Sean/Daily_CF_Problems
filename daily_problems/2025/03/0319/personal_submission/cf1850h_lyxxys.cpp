void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> p(n);
    iota(p.begin(), p.end(), 0);

    vector <i64> dist(n);
    auto find = [&](auto &&self, int u)->int{
        if (p[u] != u){
            int fa = p[u];
            p[u] = self(self, p[u]);
            dist[u] += dist[fa];
        }
        return p[u];
    };
    auto merge = [&](int x, int y, int d)->void{
        int u = find(find, x), v = find(find, y);
        if (u != v){
            p[u] = v;
            dist[u] += d + dist[y] - dist[x];
        }
    };
    auto ask = [&](int x, int y)->i64{
        if (find(find, x) != find(find, y)) return inf_i64;
        else return dist[x] - dist[y];
    };

    bool jug = 0;
    for (int i = 0,u,v,d; i < m; ++ i){
        cin >> u >> v >> d;
        u -= 1, v -= 1;
        if (jug) continue;
        swap(u, v);

        i64 x = ask(u, v);
        if (x == inf_i64){
            merge(u, v, d);
        } else {
            if (x != d) jug = 1;
        }
    }

    if (jug) cout << "NO\n";
    else cout << "YES\n";
}
