void solve(){ 
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector <int> fris(k), father(n), leaf(n), color(n);  // 向上向下bfs并染色
    for (auto &x : fris){
        cin >> x;
        x -= 1;
    }
    for (int i = 0,u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs_find = [&](auto &&self, int u, int presor)->void{
        father[u] = presor;
        leaf[u] = g[u].size() == 1;
        for (auto &v : g[u]){
            if (v == presor) continue;
            self(self, v, u);
        }
    };
    dfs_find(dfs_find, 0, -1);

    vector <int> Q1(n), Q2(n);
    int i1 = 0, j1 = -1, i2 = 0, j2 = -1;
    Q1[++ j1] = 0;
    for (auto &x : fris){
        Q2[++ j2] = x;
        color[x] = 1;
    }
    color[0] = 2;

    int r1 = j1, r2 = j2, res = 0, jg = 0;
    while (i1 <= r1 || i2 <= r2){
        while (i2 <= r2){  // 先遍历 friends 点
            int u = Q2[i2++];
            int v = father[u];  // 往父亲走
            if (color[v] == 1) continue;  // 不能走 friends 点
            if (!color[v]){
                color[v] = 1;
                Q2[++ j2] = v;
            } else {
                color[v] = 3, res += 1;  // 产生截停点
            }
        }
        while (i1 <= r1){  // 遍历 Vlad 点
            int u = Q1[i1++];
            for (auto &v : g[u]){
                if (father[v] == u){  // 往下走
                    if (!color[v]){
                        Q1[++ j1] = v;
                        color[v] = 2;
                        if (leaf[v]){
                            jg = 1;
                       }
                    }
                }
            }
        }
        if (jg) break;
        r1 = j1, r2 = j2;
    }

    if (jg) cout << -1 << "\n";
    else cout << res << "\n";
}
