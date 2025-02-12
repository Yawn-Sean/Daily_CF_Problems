void solve(){
    int n, l, m;
    cin >> n >> l >> m;
    vector<vector<vector<f64>>> f(n+1,vector<vector<f64>>(n+1,vector<f64>(l+1)));
    // f[i][j][k] 前i个巡回赛，背包容量剩下 j，赢了 k 个的概率
    vector <f64> p(n);
    vector <int> A(n);
    for (auto &x : p){
        cin >> x;
        x = x / 100;
    }
    for (auto &x : A){
        cin >> x;
    }
    vector <int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){
        return A[i] > A[j];
    });

    f[0][min(n,m)][0] = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j <= n; ++ j){
            for (int k = 0; k <= l; ++ k){
                if (f[i][j][k] < eps) continue;
                f64 &v = f[i][j][k];
                int id = idx[i];
                if (A[id] == -1){
                    if (j > 0) f[i+1][j-1][min(k+1, l)] += v*p[id];
                    f[i+1][j][k] += v*(1-p[id]);
                } else {
                    f[i+1][min(n,j+A[id])][min(k+1, l)] += v*p[id];
                    f[i+1][j][k] += v*(1-p[id]);
                }
            }
        }
    }

    f64 res = 0;
    for (int i = 0; i <= n; ++ i){
        res += f[n][i][l];
    }

    cout << fixed << setprecision(15) << res << "\n";
}
