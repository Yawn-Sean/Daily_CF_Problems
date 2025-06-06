void solve(){
    const int mod = 998244353;

    int n;
    cin >> n;
    vector<vector<int>> f(n+3,vector<int>(n+3)), acc(n+3,vector<int>(n+3));
    vector <int> nxtv(n+2), A(n+1), pw2(n+1, 1);
    iota(nxtv.begin(), nxtv.end(), 0);
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
    }

    for (int i = 0; i < n; ++ i){
        pw2[i+1] = pw2[i] * 2 % mod;
    }
    for (int i = 1; i <= n+1; ++ i){
        nxtv[i] = i;
        for (int j = i+1; j <= n; ++ j){
            if (A[j] > A[j-1]) nxtv[i] = j;
            else break;
        }
    }

    f[0][1] = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = i+1; j <= n; ++ j){
            const int &v = 1ll*f[i][j]*pw2[j-i-1]%mod;

            acc[i+1][j] += v, acc[i+1][j] %= mod;
            int &u = acc[i+1][nxtv[j+1]+1];
            u -= v, u %= mod;
            if (u < 0) u += mod;
        }

        for (int j = 1; j <= n; ++ j){
            acc[i+1][j] = (acc[i+1][j]+acc[i+1][j-1]) % mod;
            f[i+1][j] = acc[i+1][j];
        }
    }

    cout << f[n][n] << "\n";
}
