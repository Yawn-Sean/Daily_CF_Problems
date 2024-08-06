int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    priority_queue<pii> q;
    Fenwick<int> fen(n);
    
    ll res = 0;
    for (int i = n - 1; i >= 0; i --) {
        while (!em(q) and q.top().fi >= i + 1) {
            auto t = q.top().se;
            q.pop();
            fen.add(t, 1);
        } 
        int mx = min(n - 1, a[i] - 1);
        if (i + 1 <= mx) res += fen.rangeSum(i + 1, mx + 1);
        q.emplace(a[i], i);
    }
    
    cout << res << endl;
    
}