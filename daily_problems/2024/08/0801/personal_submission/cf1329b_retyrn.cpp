int d, mod;

void solve() {
    cin >> d >> mod;
    if (d == 1) {
        cout << 1 % mod << endl;
        return;
    }
    int len = 0;
    for (int i = 30; i >= 0; i --) {
        if (d >> i & 1) {
            len = i;
            break;
        }
    }
    vector<ll> pow2(40, 1 % mod);
    for (int i = 1; i < 40; i ++) {
        pow2[i] = (pow2[i - 1] << 1) % mod;
    }
    
    vector<ll> f(len + 1);
    f[0] = 1;
    ll pre = 1;
    for (int i = 1; i <= len; i ++) {
        f[i] = (pre + 1) % mod;
        pre = (pre + f[i] * pow2[i]) % mod;
    }
    ll res = 0;
    for (int i = 0; i < len; i ++) {
        res += f[i] * pow2[i];
        res %= mod;
    }
    res += (d - (1 << len) + 1) * f[len];
    res %= mod;
    cout << res << endl;
}