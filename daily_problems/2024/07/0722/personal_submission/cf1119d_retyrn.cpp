int n, m;
using pli = pair<ll, int>;

void solve() {
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    sort(all(a));
    complete_unique(a);
    n = sz(a);
    
    cin >> m;
    vector<ll> query(m);
    for (int i = 0; i < m; i ++) {
        ll l, r;
        cin >> l >> r;
        query[i] = (r - l + 1);
    }
    
    vector<int> id(m);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        return query[x] < query[y];
    });
    
    vector<ll> res(m);
    
    DSU dsu(n, a);
    priority_queue<pli, vector<pli>, greater<pli>> q;
    for (int i = 0; i < n - 1; i ++) {
        q.emplace(a[i + 1] - a[i], i);
    }
    ll cur = 0;
    int con = n;
    
    for (auto idx : id) {
        ll len = query[idx];
        while (!em(q) and q.top().fi <= len) {
            auto t = q.top();
            q.pop();
            if (dsu.same(t.se, t.se + 1)) continue;
            cur -= dsu.getR(t.se + 1) - dsu.getL(t.se + 1);
            cur -= dsu.getR(t.se) - dsu.getL(t.se);
            con -= dsu.merge(t.se, t.se + 1);
            cur += dsu.getR(t.se) - dsu.getL(t.se);
        }
        ll ans = cur + (ll)con * len;
        res[idx] = ans;
    }
    cout << res << endl;
}