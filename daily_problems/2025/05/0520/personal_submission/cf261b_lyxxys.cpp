void solve(){
    int n, m;
    cin >> n;
    vector <int> A(n);
    int cur = 0;
    for (auto &x : A){
        cin >> x;
        cur += x;
    }
    cin >> m;
    vector <f64> fact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++ i){
        fact[i] = fact[i-1] * i;
    }
    if (cur <= m){
        cout << fixed << setprecision(10) << n << "\n";
        return;
    }

    f64 res = 0;
    // 枚举 i 为结尾(恰好不行)方案中 贡献的人数，需要处理没有不合法的情况
    for (int i = 0; i < n; ++ i){
        vector<vector<f64>> f(n+1, vector<f64>(m+1));
        f[0][0] = 1;
        for (int j = 0; j < n; ++ j){
            if (j == i) continue;
            for (int u = n; u >= 1; -- u){
                for (int v = m; v-A[j] >= 0; -- v){
                    f[u][v] += f[u-1][v-A[j]];
                }
            }
        }

        for (int j = 0; j < n; ++ j){
            for (int u = 0; u <= m; ++ u){
                if (u+A[i] > m){
                    res += j * fact[j] * fact[n-j-1] * f[j][u];
                }
            }
        }
    }

    cout << fixed << setprecision(10) << res/fact[n] << "\n";
}
