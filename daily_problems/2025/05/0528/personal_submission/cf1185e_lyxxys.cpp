void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n,vector<char>(m, '.')), ans(n,vector<char>(m, '.'));
    vector<vector<int>> store(26);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            cin >> g[i][j];
            if (g[i][j] != '.'){
                store[g[i][j]-'a'].push_back(i*m+j);
            }
        }
    }

    vector<array<int,4>> opts(26);
    vector <int> vis(26);
    int tot = 0;
    for (int i = 25, jug = 0; i >= 0; -- i){
        if (store[i].size() > 0) jug = 1;
        vis[i] = jug;
        tot += jug;
    }
    
    for (int i = tot-1, ox, oy; i >= 0; -- i){
        if (vis[i]){
            if (store[i].empty()){
                opts[i] = {ox, oy, ox, oy};
                continue;  // 后面有蛇，同时被完全覆盖
            }

            bool jg1 = 1, jg2 = 1;  // jg1:所有行相同，jg2:所有列相同
            ox = store[i][0]/m, oy = store[i][0]%m;
            for (auto &id : store[i]){
                if (id/m != ox) jg1 = 0;
                if (id%m != oy) jg2 = 0;
            }
            if (!jg1 && !jg2){
                cout << "NO\n";
                return;
            }
            int l = n+m+1, r = -1;
            for (auto &id : store[i]){
                int j = jg1 ? id%m : id/m;
                fmin(l, j);
                fmax(r, j);
            }
            if (jg1){
                opts[i] = {ox, l, ox, r};
            } else {
                opts[i] = {l, oy, r, oy};
            }
        }
    }

    for (int u = 0; u < tot; ++ u){
        auto [r1, c1, r2, c2] = opts[u];
        for (int i = r1; i <= r2; ++ i){
            for (int j = c1; j <= c2; ++ j){
                ans[i][j] = char(u + 'a');
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (g[i][j] != ans[i][j]){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n" << tot << "\n";
    for (int i = 0; i < tot; ++ i){
        auto [r1, c1, r2, c2] = opts[i];
        cout << r1+1 << " " << c1+1 << " " << r2+1 << " " << c2+1 << "\n";
    }
}
