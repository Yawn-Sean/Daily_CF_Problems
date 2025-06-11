void solve(){
    auto __lcm = [&](i64 x, i64 y)->i64{
        return x*y / __gcd(x, y);
    };

    int n, m;
    cin >> n >> m;
    vector<vector<int>> gra(n), chuks, chuks_edge;
    vector <i64> lcms, gcds;
    vector<array<int,2>> uvs;
    vector <int> vis(n, -1), ans(n);

    bool jug = 1;
    for (int i = 0,u,v,g,l; i < m; ++ i){
        cin >> u >> v >> g >> l;
        u -= 1, v -= 1;
        gra[u].push_back(i);
        gra[v].push_back(i);

        gcds.push_back(g);
        lcms.push_back(l);
        uvs.push_back({u, v});
        if (l%g) jug = 0;
    }
    if (!jug){
        cout << "NO\n";
        return;
    }

    auto dfs_divide = [&](auto &&self, int u, int color, vector<int>&chuk)->void{
        vis[u] = color;
        chuk.push_back(u);
        for (auto &id : gra[u]){
            int v = uvs[id][0]+uvs[id][1] - u;
            if (vis[v] != -1) continue;
            self(self, v, color, chuk);
        }
    };
    for (int i = 0, color = 0; i < n; ++ i){
        if (vis[i] == -1){
            vector <int> chuk;
            dfs_divide(dfs_divide, i, color ++, chuk);
            chuks.push_back(chuk);
        }
    }

    const int tot = chuks.size();
    chuks_edge.resize(tot);
    for (int i = 0; i < m; ++ i){
        auto [u, v] = uvs[i];
        assert(vis[u] == vis[v]);
        chuks_edge[vis[u]].push_back(i);
    }

    auto dfs_chk = [&](auto &&self, int u)->bool{
        if (ans[u] > (int)1e6) return false;

        for (auto &id : gra[u]){
            int v = uvs[id][0]+uvs[id][1] - u;

            if (ans[v] != 0) continue;
            if (lcms[id]%ans[u] || ans[u]%gcds[id]) return false;

            ans[v] = lcms[id] * gcds[id] / ans[u];
            if (!self(self, v)) return false;
        }

        return true;
    };
    auto chk = [&](int u, int val)->bool{
        for (auto &id : chuks[vis[u]]){
            ans[id] = 0;
        }

        ans[u] = val;

        if (!dfs_chk(dfs_chk, u)) return false;

        for (auto &id : chuks_edge[vis[u]]){
            auto [u, v] = uvs[id];
            i64 g = gcds[id], l = lcms[id];
            if (__gcd(ans[u], ans[v]) != g || __lcm(ans[u], ans[v]) != l){
                return false;
            }
        }

        return true;
    };

    for (int i = 0; i < tot; ++ i){
        if (chuks[i].size()==1){
            ans[chuks[i][0]] = 1;
            continue;
        }

        int id = chuks_edge[i][0];
        int u = uvs[id][0], l = lcms[id], g = gcds[id];
        bool jug = 0;
        for (int i = 1; i*i <= l; ++ i){  // 枚举因子
            if (l%i == 0){
                int x = i, y = l/i;
                if (x%g == 0){
                    if (chk(u, x)){
                        jug = 1;
                        break;
                    }
                }
                if (x != y && y%g == 0){
                    if (chk(u, y)){
                        jug = 1;
                        break;
                    }
                }
            }
        }
        if (!jug){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    print(ans);
}
