int n, h;

void solve() {
    cin >> n >> h;
    vector<pii> a(n);
    cin >> a;
    
    // 开始起点是a[0].fi
    int j = 1;
    int sum = 0;
    while (j < n and sum + a[j].fi - a[j - 1].se < h) {
        sum += a[j].fi - a[j - 1].se;
        j ++;
    }
    int res = (h - sum) + (a[j-1].se - a[0].fi);
    
    for (int i = 1; i < n; i ++) {
        sum -= a[i].fi - a[i-1].se;
        while (j < n and sum + a[j].fi - a[j - 1].se < h) {
            sum += a[j].fi - a[j - 1].se;
            j ++;
        }
        chmax(res, (h - sum) + (a[j-1].se - a[i].fi));
    }
    cout << res << endl;
}