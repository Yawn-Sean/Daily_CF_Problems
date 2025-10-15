void solve(){
    const int mod = 998244353;    
    auto pows = [&](i64 a, int b)->int{
        i64 res = 1;
        while (b){
            if (b&1) res = res*a % mod;
            a = a*a % mod;
            b >>= 1;
        }
        return res;
    };
    int n, k;
    cin >> n >> k;
    i64 ans = 0, cur = 1;
    for (int i = 0; i <= min(n,k); ++ i){
        ans += cur * (pows(i+1, k-i+1) - pows(i, k-i+1)) % mod;
        cur = cur * (n-i) % mod * (i+1) % mod;
        ans %= mod;
        if (ans < 0) ans += mod;
    }

    cout << ans << "\n";
}
