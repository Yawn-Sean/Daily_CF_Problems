void solve(){
    int n, k;
    cin >> n >> k;
    const int N = 1 << k, mod = 1000000007, tar = 1 << k, msk = (1<<k) - 1;

    vector <int> A(n+1), sf(n+2);
    vector <i64> pw2(n+1, 1);
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
        pw2[i] = pw2[i-1] * 2 % mod;
    }
    for (int i = n; i > 0; -- i){
        sf[i] = sf[i+1] + (A[i] == 0);
    }

    i64 res = 0;
    vector<vector<i64>> f(n+1, vector<i64>(N));
    f[0][0] = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < tar; ++ j){
            if (A[i+1] == 0){

                if (j>>1 & 1){
                    f[i+1][4] += f[i][j], f[i+1][4] %= mod;
                } else {
                    if (j >= tar-4) res += f[i][j] * pw2[sf[i+2]] % mod, res %= mod;
                    else f[i+1][j+4] += f[i][j], f[i+1][j+4] %= mod;
                }

                if (j >= tar-2) res += f[i][j] * pw2[sf[i+2]] % mod, res %= mod;
                else f[i+1][j+2] += f[i][j], f[i+1][j+2] %= mod;

            } else if (A[i+1] == 2){

                if (j >= tar-2) res += f[i][j] * pw2[sf[i+2]] % mod, res %= mod;
                else f[i+1][j+2] += f[i][j], f[i+1][j+2] %= mod;

            } else {

                if (j>>1 & 1){
                    f[i+1][4] += f[i][j], f[i+1][4] %= mod;
                } else {
                    if (j >= tar-4) res += f[i][j] * pw2[sf[i+2]] % mod, res %= mod;
                    else f[i+1][j+4] += f[i][j], f[i+1][j+4] %= mod;
                }
                
            }
        }
    }

    cout << res << "\n";
}
