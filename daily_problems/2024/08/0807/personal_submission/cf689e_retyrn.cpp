int n, k;

void solve() {
    cin >> n >> k;
    vector<pii> a(n);
    cin >> a;
    sort(all(a));
    
    vector<int> p;
    for (auto& [x, y] : a) {
        p.push_back(x);
        p.push_back(y + 1);
    }
    sort(all(p));
    complete_unique(p);
    
    int idx = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    Z res = 0;
    for (int i = 0; i < sz(p); i ++) {
        auto x = p[i];
        while (idx < n and a[idx].fi <= x) {
            q.push(a[idx].se);
            idx ++;
        }
        while (!em(q) and q.top() < x) q.pop();
        
        int sum = sz(q), cnt = (i + 1 < sz(p) ? p[i + 1] - p[i] : 1);
        if (sum >= k) {
            res += comb.binom(sum, k) * cnt;
        }
    }
    cout << res << endl;
}