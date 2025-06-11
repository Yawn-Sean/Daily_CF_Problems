void solve(){
    int n, m;
    f64 p1;
    cin >> n >> p1 >> m;
    const f64 p2 = 1-p1;

    vector<vector<f64>> f(m+1, vector<f64>(n+1));
    
    f[0][0] = 1;
    for (int i = 0; i < m; ++ i){
        for (int j = 0; j <= n; ++ j){
            f64 &v = f[i][j];
            if (j == n){
                f[i+1][j] += v;
            } else {
                f[i+1][j+1] += p1 * v;
                f[i+1][j] += p2 * v;      
            }
        }
    }

    f64 res = 0;
    for (int j = 1; j <= n; ++ j){
        res += f[m][j] * j;
    }

    cout << fixed << setprecision(10) << res << "\n";
}
