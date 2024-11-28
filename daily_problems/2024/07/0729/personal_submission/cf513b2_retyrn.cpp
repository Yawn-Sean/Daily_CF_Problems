int n;
ll m;

void solve() {
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    // 一共 2^(n-1)个
    ll t = 1LL << (n - 2);
    vector<int> res(n);
    int l = 0, r = n - 1, idx = 1;
    while (l < r) {
        if (m <= t) res[l ++] = idx ++;
        else {
            m -= t;
            res[r --] = idx ++;
        }
        t >>= 1;
    }
    res[l] = n;
    cout << res << endl;
}