using ai3 = array<int, 3>;
int n, m;

void solve() {
    cin >> n >> m;
    vector<ai3> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i + 1;
    }
    sort(all(a));
    
    int mx = -inf, pos = -1;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < m; i ++) {
        q.push(a[i][1]);
    }
    if (q.top() - a[m - 1][0] + 1 > mx) {
        mx = q.top() - a[m - 1][0] + 1;
        pos = m - 1;
    }
    
    for (int i = m; i < n; i ++) {
        q.push(a[i][1]);
        q.pop();
        if (q.top() - a[i][0] + 1 > mx) {
            mx = q.top() - a[i][0] + 1;
            pos = i;
        }
    }
    if (mx <= 0) {
        cout << 0 << endl;
        for (int i = 1; i <= m; i ++) {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }
    
    cout << mx << endl;
    priority_queue<pii, vector<pii>, greater<pii>> q1;
    for (int i = 0; i <= pos; i ++) {
        q1.push(mpr(a[i][1], a[i][2]));
    }
    while (sz(q1) > m) {
        q1.pop();
    }
    
    vector<int> res;
    while (!em(q1)) {
        auto t = q1.top().se;
        q1.pop();
        res.pbk(t);
    }
    sort(all(res));
    cout << res << endl;
}