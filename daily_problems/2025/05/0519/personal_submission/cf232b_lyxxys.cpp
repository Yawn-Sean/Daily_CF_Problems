void solve(){
    const int mod = 1e9+7;
    auto pows = [&](i64 a, i64 b)->i64{
        i64 res = 1;
        while (b){
            if (b&1) res = res * a % mod;
            a = a*a % mod;
            b >>= 1;
        }
        return res;
    };

    i64 n, m, k;
    cin >> n >> m >> k;

    const int N = n;
    vector <i64> fact1(N+1, 1), fact2(N+1, 1);
    for (int i = 1; i <= N; ++ i){
        fact1[i] = fact1[i-1] * i % mod;
    }
    fact2[N] = pows(fact1[N], mod-2);
    for (int i = N; i >= 1; -- i){
        fact2[i-1] = fact2[i] * i % mod;
    }
    auto comb = [&](int i, int j)->i64{
        if (j > i) return 0;
        else return fact1[i] * fact2[j] % mod * fact2[i-j] % mod;
    };

    i64 res = 0;
    i64 a = m/n, b = m%n;
    /*
        前 i 列且有 j 个点的方案
        当第 i 列的点数确定了，那么关于 j%n = i 的 j 列的点数也都确定了
        只要把 n 的模枚举完，就枚举完了前 m 列的方案
    */
    vector<i64> f1(k+1), f2(k+1);

    f1[0] = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j <= n; ++ j){
            i64 v = pows(comb(n, j), i < b ? a+1 : a);
            for (int u = k; u >= j; -- u){
                f2[u] += f1[u - j] * v % mod;
                f2[u] %= mod;
            }
        }
        for (int u = 0; u <= k; ++ u){
            f1[u] = f2[u];
            f2[u] = 0;
        }
    }

    cout << f1[k] << "\n";
}
