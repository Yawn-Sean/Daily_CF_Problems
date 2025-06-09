void solve(){
    using fint = vector<vector<i64>>;
    const int mod = 1e9+7;
    auto multi = [&](fint M1, fint M2){
        int n1 = M1.size(), n2 = M1[0].size(), n3 = M2[0].size();
        fint ans(n1, vector<i64>(n3));
        for (int i = 0; i < n1; ++ i){
            for (int j = 0; j < n3; ++ j){
                for (int u = 0; u < n2; ++ u){
                    ans[i][j] += M1[i][u] * M2[u][j] % mod;
                    ans[i][j] %= mod;
                }
            }
        }
        return ans;
    };

    int n, m;
    cin >> m >> n;
    vector <i64> s(m), l(m);
    for (int i = 0; i < m; ++ i){
        cin >> s[i];
    }
    for (int i = 0; i < m; ++ i){
        cin >> l[i];
    }

    fint A(1, vector<i64>(2));  // [短， 长]
    fint B(2, vector<i64>(2));
    A[0][0] = s[0], A[0][1] = l[0];
    for (int i = 0; i < m; ++ i){
        (B[0][0] += (s[i]+l[i]) * s[i] % mod) %= mod;
        (B[0][1] += (s[i]+l[i]) * l[i] % mod) %= mod;
        (B[1][0] += s[i] * s[i] % mod) %= mod;
        (B[1][1] += s[i] * l[i] % mod) %= mod;
    }

    n -= 1;
    while (n){
        if (n&1) A = multi(A, B);
        B = multi(B, B);
        n >>= 1;
    }

    i64 res = 0;
    for (int i = 0; i < m; ++ i){
        res += A[0][0] * (s[i]+l[i]) % mod;
        res += A[0][1] * s[i] % mod;
        res %= mod;
    }
    cout << res << "\n";
}
