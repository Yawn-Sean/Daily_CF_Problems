int n;

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
    cin >> n;
    vector<int> b(n);
    cin >> b;

    vector<int> c2(50);
    for (int i = 0; i < n; i ++) {
        int x = b[i], cnt = 0;
        while (x % 2 == 0) {
            x >>= 1;
            cnt += 1;
        }
        c2[cnt] += 1;
    }
    
    int pre = 0;
    ll res = 0;
    for (int i = 30; i > 0; i --) {
        if (c2[i] >= 2) {
            // 要选偶数个 且不为0
            res = (res + (powmod(2, c2[i] - 1) + mod - 1) * powmod(2, pre)) % mod;
        }
        pre += c2[i];
    }
    
    res = (res + (powmod(2, c2[0]) + mod - 1) * powmod(2, pre)) % mod;
    cout << res << endl;
}