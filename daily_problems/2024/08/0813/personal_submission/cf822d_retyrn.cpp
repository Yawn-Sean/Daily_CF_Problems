int t, l, r;
ll f[maxn];

void solve() {
    cin >> t >> l >> r;
    memset(f, 0x3f, sizeof f);
    f[1] = 0;
    for (int i = 1; i <= r; i ++) {
        for (int j = 2; j * i <= r; j ++) {
            chmin(f[i * j], f[i] + (ll)j * (j - 1) / 2 * i);
        }
    }
    
    int res = 0, cur = 1;
    for (int i = l; i <= r; i ++) {
        res = (res + f[i] % mod * cur) % mod;
        cur = (ll)cur * t % mod;
    }
    cout << res << endl;
}