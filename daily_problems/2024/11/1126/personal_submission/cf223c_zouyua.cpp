int main()
{
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1), res(n + 1), f(n + 1, 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    Comb comb(20020);
    for(int i = 1; i <= n; i ++) {
        f[i] = f[i - 1] * (k + i - 1) % mod * (comb.fac[i - 1]) % mod * comb.invfac[i] % mod;   
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= i; j ++) {
            res[i] = (res[i] + a[j] % mod  * f[i - j]) % mod;
        }
        cout <<res[i] << " \n"[i == n];
    }
    return 0;
}
