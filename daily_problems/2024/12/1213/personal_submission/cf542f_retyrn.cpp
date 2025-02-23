int n, k;

void solve() {
    cin >> n >> k;
    vector<pii> a(n);
    cin >> a;
    
    priority_queue<pii> q;
    
    for (auto [t, w] : a) {
        q.emplace(k - t, w);
    }
    
    while (sz(q) and q.top().fi > 0) {
        auto [layer, w] = q.top();
        q.pop();
        if (sz(q) and q.top().fi == layer) {
            auto [layer1, w1] = q.top();
            q.pop();
            w += w1;
        }
        q.emplace(layer - 1, w);
    }
    
    cout << q.top().se << endl;
}