int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    BIT<int> bit(maxn);
    vector<int> f(maxn, 0);
    bit.add(1, 1);
    
    for (auto x : a) {
        int val = ((ll)bit.sum(x + 1) * x % mod + mod - f[x]) % mod;
        f[x] += val;
        f[x] %= mod;
        bit.add(x + 1, val);
    }
    int res = 0;
    for (int i = 1; i <= 1000000; i ++) {
        res = (res + f[i]) % mod;
    }
    cout << res << endl;
}