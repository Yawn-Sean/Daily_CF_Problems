using tp = tuple<ll, ll, int>;
int n;
ll x;

void solve() {
    cin >> x >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i ++) {
        int m;
        cin >> m;
        g[i].resize(m);
        cin >> g[i];
    }
    vector<int> id(n, 0);

    // 多路归并 维护一个堆保持cost的最大值和总体获利
    priority_queue<tp> q;
    
    function<void(int)> get = [&](int u) {
        if (id[u] >= sz(g[u])) return;
        int t = id[u];
        ll sum = g[u][t], mn = sum;
        while (sum <= 0 and t + 1 < sz(g[u])) {
            sum += g[u][t + 1];
            mn = min(mn, sum);
            t ++;
        }
        id[u] = t + 1;
        if (sum > 0) {
            q.push({mn, sum, u});
        }
    };
    
    for (int i = 0; i < n; i ++) {
        get(i);
    }
    
    while (!em(q)) {
        auto [mn, sum, u] = q.top();
        q.pop();
        if (x + mn >= 0) {
            x += sum;
            get(u);
        }
    }
    cout << x << endl;
}