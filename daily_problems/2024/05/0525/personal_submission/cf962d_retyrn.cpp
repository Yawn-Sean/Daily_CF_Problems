using pll = pair<ll, ll>;
int n;

void solve() {
    cin >> n;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    vector<pll> res;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        q.emplace(x, i);
    }
    
    while (sz(q) >= 2) {
        auto [x1, p1] = q.top();
        q.pop();
        auto [x2, p2] = q.top();
        q.pop();
        if (x1 != x2) {
            res.emplace_back(p1, x1);
            q.emplace(x2, p2);
        }
        else {
            q.emplace(x1 * 2, p2);
        }
    }
    while (!em(q)) {
        auto [x1, p1] = q.top();
        q.pop();
        res.emplace_back(p1, x1);
    }
    
    sort(all(res));
    cout << sz(res) << endl;
    for (auto [_, x] : res) {
        cout << x << ' ';
    }
    cout << endl;
}