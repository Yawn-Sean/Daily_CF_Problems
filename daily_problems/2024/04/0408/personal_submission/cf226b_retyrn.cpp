int n, m;

void solve() {
    cin >> n;
    vector<int> a(n);
    // 第一层是1 第二层是k个 第三层是k^2个 第四层是k^3个
    cin >> a;
    sort(all(a), greater<int>());
    vector<ll> s(n + 1, 0ll);
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i - 1];
    }
    
    // 特判k为1
    ll res1 = 0;
    for (int i = 0; i < n; i ++) {
        res1 += (ll)i * a[i];
    }
    
    cin >> m;
    while (m --) {
        int k;
        cin >> k;
        if (k == 1) {
            cout << res1 << ' ';
            continue; 
        }
        ll layer = 0, st = 0, len = 1, res = 0;
        while (st < n) {
            auto ed = min((ll)n - 1, st + len - 1);
            // [st, ed]
            res += layer * (s[ed + 1] - s[st]);
            layer += 1;
            len *= k;
            st = ed + 1;
        }
        cout << res << ' ';
    }
    cout << endl;
}