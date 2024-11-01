ll n, k;

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
    cin >> n >> k;
    if (!n) {
        cout << 0 << endl;
        return;
    }
    // [2^k*x - 2^k + 1, 2^k*x]
    // 2^k (2x - 1) + 1
    n %= mod;
    ll res = ((n * 2 - 1 + mod) % mod * powmod(2, k) + 1) % mod;
    cout << res << endl;
}