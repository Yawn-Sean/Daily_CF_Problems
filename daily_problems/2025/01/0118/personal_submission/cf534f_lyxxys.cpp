void solve(){
    static bool f[20][32][11][11][11][11][11];
    auto find = [&](int x)->int{
        int i = 0;
        int res = 0;
        while (i < 5){
            if (x>>i & 1){
                res += 1;
                while (x>>i & 1){
                    i += 1;
                }
            }
            i += 1;
        }
        return res;
    };

    int n, m;
    cin >> n >> m;
    vector <vector<int>> gs(5);
    vector <int> A(n), B(m);
    for (auto &x : A){
        cin >> x;
    }
    for (auto &x : B){
        cin >> x;
    }

    for (int i = 0; i < 1<<n; ++ i){
        gs[find(i)].push_back(i);
    }

    vector<vector<char>> ans(n,vector<char>(m, '?'));
    auto print = [&]()->void{
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                cout << ans[i][j];
            }
            cout << "\n";
        }
    };

    bool jg = 0;
    auto dfs = [&](auto &&self, int col, int lst, vector<int> us)->void{
        if (jg) return;

        for (int i = 0; i < n; ++ i){
            if (us[i] > A[i] || m-col < A[i]-us[i]){
                return;
            }
        }
        if (col == m){
            jg = 1;
            print();
            return;
        }

        if (f[col][lst][us[0]][us[1]][us[2]][us[3]][us[4]]) return;
        f[col][lst][us[0]][us[1]][us[2]][us[3]][us[4]] = 1;

        for (auto &u : gs[B[col]]){
            vector <int> nxt_us = us;
            for (int i = 0; i < n; ++ i){
                if ((u>>i&1) == 1){
                    ans[i][col] = '*';
                    if ((lst>>i&1) == 0){
                        nxt_us[i] += 1;
                    }
                } else ans[i][col] = '.';
            }
            self(self, col+1, u, nxt_us);
        }
    };

    dfs(dfs, 0, 0, vector<int>(5,0));
    
}
