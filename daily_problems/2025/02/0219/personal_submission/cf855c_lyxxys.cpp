void solve(){
    const int mod = 1e9+7;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0,u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k, x;
    cin >> k >> x;
    vector<vector<vector<i64>>> f(n,vector<vector<i64>>(x+1, vector<i64>(3)));
    
    auto dfs_find = [&](auto &&self, int u, int presor)->void{
        f[u][0][0] = k-1;
        f[u][1][1] = 1;
        f[u][0][2] = m-k;

        for (auto &v : g[u]){
            if (v == presor) continue;
            self(self, v, u);

            vector <vector<i64>> curs(x+1, vector<i64>(3));
            for (int i = 0; i <= x; ++ i){
                for (int j = 0; j <= x-i; ++ j){
                    curs[i+j][0] += f[u][i][0] * (f[v][j][0]+f[v][j][1]+f[v][j][2]);
                    curs[i+j][1] += f[u][i][1] * f[v][j][0];
                    curs[i+j][2] += f[u][i][2] * (f[v][j][0]+f[v][j][2]);

                    curs[i+j][0] %= mod;
                    curs[i+j][1] %= mod;
                    curs[i+j][2] %= mod;
                }
            }

            f[u] = curs;
        }
    };

    dfs_find(dfs_find, 0, -1);

    i64 res = 0;
    for (int i = 0; i <= x; ++ i){
        res += f[0][i][0] + f[0][i][1] + f[0][i][2];
        res %= mod;
    }
    cout << res << "\n";
}
