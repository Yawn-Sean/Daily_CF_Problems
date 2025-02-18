int n, m;

void solve() {
    cin >> n >> m;
    vector<pii> a(n);
    cin >> a;
    priority_queue<int> q;
    vector<int> id(n);
    iota(all(id), 0);
    
    sort(all(id), [&](int x, int y) {
        return a[x].fi > a[y].fi;
    });
    
    int sum = 0, j = 0;
    int mx = 0, ansk = -1;
    
    for (int k = n; k > 0; k --) {
        while (j < n and a[id[j]].fi >= k) {
            sum += a[id[j]].se;
            q.push(a[id[j]].se);
            j ++;
        }
        while (sum > m or sz(q) > k) {
            sum -= q.top();
            q.pop();
        }
        if (sz(q) > mx) {
            mx = sz(q);
            ansk = k;
        }
    }
    if (ansk < 0) {
        cout << 0 << endl;
        cout << 0 << endl;
        return;
    }
    
    priority_queue<pii> q1;
    
    sum = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i].fi < ansk) continue;
        q1.emplace(a[i].se, i + 1);
    }
    while (sum > m or sz(q1) > mx) {
        q1.pop();
    }
    
    cout << mx << endl;
    vector<int> res;
    
    while (sz(q1)) {
        int t = q1.top().se;
        q1.pop();
        res.push_back(t);
    }
    cout << sz(res) << endl;
    cout << res << endl;
}