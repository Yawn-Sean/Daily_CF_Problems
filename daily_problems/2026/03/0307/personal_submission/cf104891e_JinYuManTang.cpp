void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), deg(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int cnt = 0;
    vector<int> stk;
    for (int x: a) {
        while (!stk.empty() && stk.back() < x) {
            stk.pop_back();
        }
        if (!stk.empty()) {
            g[stk.back()].push_back(x);
            deg[x]++;
            cnt++;
        }
        stk.push_back(x);
    }
    stk.clear();
    for (int x: b) {
        while (!stk.empty() && stk.back() > x) {
            stk.pop_back();
        }
        if (!stk.empty()) {
            g[stk.back()].push_back(x);
            deg[x]++;
            cnt++;
        }
        stk.push_back(x);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> tmp_deg = deg;
    vector<int> na;
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        na.push_back(u);
        for (int v: g[u]) {
            tmp_deg[v]--;
            if (!tmp_deg[v]) {
                pq.push(v);
            }
        }
    }
    tmp_deg = deg;
    vector<int> nb;
    priority_queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        nb.push_back(u);
        for (int v: g[u]) {
            tmp_deg[v]--;
            if (!tmp_deg[v]) {
                q.push(v);
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (i >= na.size() || i >= nb.size() || na[i] != a[i] || nb[i] != b[i]) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        cout << cnt << '\n';
        for (int u = 1; u <= n; u++) {
            for (int v: g[u]) {
                cout << u << ' ' << v << '\n';
            }
        }
    }
}
