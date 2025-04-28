void solve(){
    int n, mod;
    cin >> n;
    map <int,int> mps;
    vector <int> A(n), B(n);
    for (int i = 0; i < n; ++ i){
        cin >> A[i];
        mps[A[i]] += 1;
    }
    for (int i = 0; i < n; ++ i){
        cin >> B[i];
        mps[B[i]] += 1;
    }
    cin >> mod;

    int to2 = 0;
    for (int i = 0; i < n; ++ i){
        if (A[i] == B[i]){
            to2 += 1;
        }
    }

    i64 res = 1;
    for (auto &it : mps){
        auto L = it.second;
        for (i64 j = 1; j <= L; ++ j){
            i64 u = j;
            while (to2 > 0 && u%2 == 0){
                u /= 2;
                to2 -= 1;
            }
            res = res * u % mod;
        }
    }

    cout << res << "\n";
}
