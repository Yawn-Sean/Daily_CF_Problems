void solve(){
    int n, k, r;
    cin >> n >> k >> r;
    vector <i64> as(n), bs(n), cs(n), ps(n);
    for (int i = 0; i < n; ++ i){
        cin >> as[i];
    }
    for (int i = 0; i < n; ++ i){
        cin >> bs[i];
    }
    for (int i = 0; i < n; ++ i){
        cin >> cs[i];
    }
    for (int i = 0; i < n; ++ i){
        cin >> ps[i];
        ps[i] -= 1;
    }

    i64 res = -inf_i64;
    auto Reco = [&](vector<i64>&A)->void{
        i64 ans = 0;
        for (int i = 0; i < n; ++ i){
            ans += A[i]*cs[i];
        }
        fmax(res, ans);
    };
    auto OP1 = [&](vector<i64>&A)->vector<i64>{
        vector <i64> B(n);
        for (int i = 0; i < n; ++ i){
            B[i] = (A[i]^bs[i]);
        }
        return B;
    };
    auto OP2 = [&](vector<i64>&A)->vector<i64>{
        vector <i64> B(n);
        for (int i = 0; i < n; ++ i){
            B[i] = A[ps[i]] + r;
        }
        return B;
    };

    auto dfs_brute = [&](auto &&self, vector<i64>curs, int step, bool is_xor)->void{
        if ((k-step)%2 == 0){
            Reco(curs);
            if (step >= k) return;
        }
        if (!is_xor) self(self, OP1(curs), step+1, 1);
        self(self, OP2(curs), step+1, 0);
    };
    dfs_brute(dfs_brute, as, 0, 0);

    cout << res << "\n";
}
