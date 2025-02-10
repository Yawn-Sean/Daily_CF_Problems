void solve(){
    const int mod = 998244353;
    const int inv2 = mod - mod/2;
    const int inv4 = 1ll*inv2*inv2 % mod;

    int n;
    cin >> n;
    vector <i64> f(n+1);
    f[0] = 1;

    i64 f0 = f[0]*inv2, f1 = 0;
    for (int i = 1; i <= n; ++ i){
        if (i%2){
            f[i] = f0;
            f1 = (f1*inv4 + f[i]*inv2) % mod;
        } else {
            f[i] = f1;
            f0 = (f0*inv4 + f[i]*inv2) % mod;
        }
    }

    cout << f[n] << "\n";
}
