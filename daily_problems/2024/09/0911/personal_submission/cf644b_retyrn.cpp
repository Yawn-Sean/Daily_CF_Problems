int n, b;
using ai3 = array<int, 3>;

void solve() {
    cin >> n >> b;
    ll time = -1;
    vector<pii> a(n);
    cin >> a;
    
    queue<ai3> q;
    vector<ll> res(n);
    
    for (int i = 0; i < n; i ++) {
        while (sz(q) and time <= a[i].fi) {
            auto t = q.front();
            q.pop();
            int id = t[0];
            time = max(time, (ll)t[1]) + t[2];
            res[id] = time;
        }
        if (sz(q) >= b) {
            res[i] = -1;
        }
        else q.push({i, a[i].fi, a[i].se});
    }
    
    while (sz(q)) {
        auto t = q.front();
        q.pop();
        time = max(time, (ll)t[1]) + t[2];
        res[t[0]] = time;
    }
    cout << res << endl;
}