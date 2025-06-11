int n;

void solve() {
    cin >> n;
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<int> res;
    res.push_back(1);
    int x = a[1].fi, y = a[1].se;
    if (a[x].fi == y or a[x].se == y) {
        res.push_back(x);
        res.push_back(y);
    }
    else {
        res.push_back(y);
        res.push_back(x);
    }
    
    for (int i = 1; i < n - 2; i ++) {
        if (res[i + 1] == a[res[i]].fi) res.push_back(a[res[i]].se);
        else res.push_back(a[res[i]].fi);
    }
    cout << res << endl;
    
}