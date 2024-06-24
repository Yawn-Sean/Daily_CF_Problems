int n, q;

void solve() {
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    sort(all(a));
    vector<ll> s(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i - 1];
    }
    
    set<ll> S;
    function<void(int, int)> dfs = [&](int l, int r) {
        if (l > r) return;
        if (a[l] == a[r]) {
            S.insert((ll)(r - l + 1) * a[l]);
            return;
        }
        dbg(l, r);
        S.insert(s[r + 1] - s[l]);
        
        int val = (a[l] + a[r]) >> 1;
        int mid = upper_bound(all(a), val) - a.begin();
        dfs(l, mid - 1);
        dfs(mid, r);
    };
    
    dfs(0, n - 1);
    
    while (q --) {
        int x;
        cin >> x;
        cout << (S.count(x) ? "Yes" : "No") << endl;
    }
}