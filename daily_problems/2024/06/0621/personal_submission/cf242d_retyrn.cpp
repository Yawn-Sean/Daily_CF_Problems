int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> a(n);
    cin >> a;
    
    queue<int> q;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i ++) {
        if (a[i] == 0) {
            q.push(i);
        }
    }
    vector<int> res;
    while (!em(q)) {
        auto t = q.front();
        q.pop();
        if (cnt[t] > a[t]) continue;
        res.push_back(t);
        cnt[t] += 1;
        for (auto x : g[t]) {
            if (++ cnt[x] == a[x]) {
                q.push(x);
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        if (a[i] == cnt[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << sz(res) << endl;
    for (auto x : res) {
        cout << x + 1 << ' ';
    }
    cout << endl;
}