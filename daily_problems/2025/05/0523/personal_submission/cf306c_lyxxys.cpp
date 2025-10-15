void solve(){
    const int mod = 1e9+9;

    int n, w, b;
    cin >> n >> w >> b;
    const int N = max(w, b);
    vector<vector<i64>> C(N+1, vector<i64>(N+1));
    vector <i64> fact(N+1, 1);
    for (int i = 0; i <= N; ++ i){
        for (int j = 0; j <= i; ++ j){
            if (j == 0){
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
            }
        }
    }
    for (int i = 1; i <= N; ++ i){
        fact[i] = fact[i-1] * i % mod;
    }

    i64 res = 0;
    /*
        枚举坏事发生的天数，那么已知坏事发生的总数目，就可以根据隔板法求出坏事分配的方案数。
        同时也知道了好事发生的天数，好事发生的总数目，同理求出好事分配的方案数
        考虑将一段坏事插入一段好事中，那么方案数是 好事数量-1(插入一段好事的间隙中)
    */
    for (int i = 1; i < n-1; ++ i){
        if (n-i-1 > w-1 || i-1 > b-1) continue;
        res += C[b-1][i-1] * C[w-1][n-i-1] % mod * (n-1-i) % mod;
        res %= mod;
    }

    cout << res*fact[w] % mod * fact[b] % mod << "\n";
}
