int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    Fenwick<int> fen(n + 1);
    ll ans = 0;
    for (auto x : a) {
        ans += fen.rangeSum(x + 1, n);
        fen.add(x, 1);
    }
    
    // 减少的逆序对数
    int mx = 0, cnt = 0;
    for (int i = 0; i < n; i ++) {
        Fenwick<int> fen(n + 1);
        for (int j = i + 1; j < n; j ++) {
            if (a[i] > a[j]) {
                int val = fen.rangeSum(a[j], a[i]) * 2 + 1;
                if (val > mx) {
                    mx = val;
                    cnt = 1;
                }
                else if (val == mx) cnt ++;
            }
            fen.add(a[j], 1);
        }
    }
    
    cout << ans - mx << ' ' << cnt << endl;
    
}