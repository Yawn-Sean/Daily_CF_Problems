void solve(){
    using fint = vector<vector<i64>>;
    const int mod = 1e9+7;
    auto multi = [&](fint M1, fint M2){
        int n1 = M1.size(), n2 = M1[0].size(), n3 = M2[0].size();
        assert(n2 == M2.size());
        fint ans(n1, vector<i64>(n3));

        for (int u = 0; u < n1; ++ u){
            for (int v = 0; v < n3; ++ v){
                for (int i = 0; i < n2; ++ i){
                    ans[u][v] += M1[u][i] * M2[i][v] % mod;
                    ans[u][v] %= mod;
                }
            }
        }

        return ans;
    };

    int n, m;
    cin >> n >> m;
    vector <array<int,2>> sl(n);
    fint A(1,vector<i64>(n));
    fint B(n,vector<i64>(n));
    for (int i = 0; i < n; ++ i){
        cin >> sl[i][0];
    }
    for (int i = 0; i < n; ++ i){
        cin >> sl[i][1];
    }

    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            i64 v1 = sl[i][0]+sl[i][1], v2 = sl[j][0]+sl[j][1];
            B[i][j] = v1*v2 - (sl[i][1] * sl[j][1]);
        }
    }

    A[0][0] = 1;
    
    while (m){
        if (m&1) A = multi(A, B);
        B = multi(B, B);
        m >>= 1;
    }

    i64 res = 0;
    for (int i = 0; i < n; ++ i){
        res += A[0][i];
        res %= mod;
    }

    cout << res << "\n";
}
