int A, B, x;
ll n;

ll powmod (ll a, ll b) {
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for(; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

void solve() {
    cin >> A >> B >> n >> x;
    ll res1 = powmod(A, n) * x % mod;
    
    function<ll(ll)> dfs = [&](ll n) -> ll {
        if (n == 1) return 1LL;
        if (n & 1) {
            ll ret = dfs(n - 1);
            ret += powmod(A, n-1);
            ret %= mod;
            return ret;
        }
        
        ll ret = dfs(n / 2) * (powmod(A, n / 2) + 1) % mod;
        return ret;
    };
    
    ll res2 = dfs(n) * B % mod;
    ll res = (res1 + res2) % mod;
    cout << res << endl;
}