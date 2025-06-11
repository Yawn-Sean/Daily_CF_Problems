auto solve = [] () {
    ll n, m;
    cin >> n >> m;
    ll mod = 1e9 + 7;
    vector<ll> f1(n, 0);
    vector<ll> f2(n, 0);
    fw(i, 0, n) cin >> f1[i];
    fw(i, 0, n) cin >> f2[i];
    auto qsm = [&] (ll a, ll n) {
        ll res = 1;
        while(n) {
            if(n & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            n /= 2;
        }
        return res;
    };
    ll x = qsm(m, mod - 2) % mod;
    vector<ll> f(n + 1, 0);
    for(ll i = n - 1; i >= 0; i -= 1) {
        ll res = f[i];
        ll v1 = f1[i];
        ll v2 = f2[i];
        if(v1 > 0 && v2 > 0) {
            if(v1 >= v2) {
                if(v1 > v2) res = 1;
                else res = (res + f[i + 1]) % mod;
            }
        } else if(v1 > 0 && v2 == 0) {
            res = (res + 1 * x * f[i + 1] % mod);
            if(v1 > 1) {
                res = (res + (v1 - 1) * x % mod) % mod;
            }
        } else if(v1 == 0 && v2 > 0) {
            res = (res + 1 * x * f[i + 1] % mod);
            if(v2 < m) {
                res = (res + (m - v2) * x % mod) % mod;
            }
        } else {
            res = (res + 1 * x * f[i + 1] % mod);
            res = (res + (m - 1) * qsm(2 * m, mod - 2) % mod) % mod;
        }
        f[i] = res;
    }
    cout << f[0] << endl;
};
