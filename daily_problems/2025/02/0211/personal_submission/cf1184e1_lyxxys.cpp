struct dsu {
    vector <int> p, sz, add;
    dsu(){}
    dsu(int n): p(n+1), sz(n+1, 1){
        iota(p.begin(), p.end(), 0);
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    int root(int x){
        return p[x] = x==p[x] ? x : root(p[x]);
    }
    int size(int x){
        return sz[root(x)];
    }
    void merge(int x, int y){
        x = root(x), y = root(y);
        if (x == y) return;
        if (size(x) < size(y)) swap(x, y);
        sz[x] += sz[y], p[y] = x;
    }
};


void solve(){
    using ary3 = array<int,3>;

    int n, m;
    cin >> n >> m;
    vector<vector<array<int,2>>> g(n);
    dsu unis(n);

    int u0, v0, e0;
    cin >> u0 >> v0 >> e0;
    u0 -= 1, v0 -= 1;
    if (u0 > v0) swap(u0, v0);

    vector<ary3> edgs(m-1);
    
    for (auto &it : edgs){
        cin >> it[0] >> it[1] >> it[2];
        if (it[0] > it[1]) swap(it[0], it[1]);
        it[0] -= 1, it[1] -= 1;
    }
    sort(edgs.begin(), edgs.end(), [&](auto &u, auto &v){
        return u[2] < v[2];
    });

    int cnt = 0;
    for (auto &[u,v,e] : edgs){  // 对 m-1 条边 做 最小生成树，剔除第一条边
        if (!unis.same(u,v)){
            g[u].push_back({v,e});
            g[v].push_back({u,e});
            unis.merge(u, v);
            cnt += 1;
        }
        if (cnt == n-1) break;
    }
    int res = 0;
    auto dfs_find = [&](auto &&self, int u, int presor, int ma)->void{
        if (u == v0){
            res = ma;
            return;
        }

        for (auto &[v,e] : g[u]){
            if (v == presor) continue;
            self(self, v, u, max(ma, e));
        }
    };

    if (cnt < n-1){
        cout << 1000000000 << "\n";
    } else {
        dfs_find(dfs_find, u0, -1, 0);
        cout << res << "\n";
    }
}
