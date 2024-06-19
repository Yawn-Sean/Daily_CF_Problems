int n;

void solve() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    
    BIT<ll> bitsum(n * 3 + 10);
    BIT<int> bitcnt(n * 3 + 10);
    
    auto query = [&](int base) {
        ll ret = (ll)bitcnt.sum(base - 1 + n) * base - bitsum.sum(base - 1 + n) + bitsum.sum(base + n, n * 3) - (ll)bitcnt.sum(base + n, n * 3) * base;
        return ret;
    };
    
    auto add = [&](int val, int d) {
        bitcnt.add(val + n, d);
        bitsum.add(val + n, val * d);
    };
    
    for (int i = 1; i <= n; i ++) {
        int t = a[i] - i;
        add(t, 1);
    }
    ll mn = query(0);
    int k = 0, base = 0;
    
    // 枚举移动哪个数到最前面
    for (int i = n; i > 1; i --) {
        int t = a[i] - i;
        add(t, -1);
        base += 1;
        // a[i]-i
        add(a[i] - 1 + base, 1);
        ll cur = query(base);
        if (cur < mn) {
            mn = cur;
            k = 1 + (n - i);
        }
    }
    cout << mn << ' ' << k << endl;
}