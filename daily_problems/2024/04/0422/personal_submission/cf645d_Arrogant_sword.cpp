void solve(int _) 
{
    int n, m;
    cin >> n >> m;
    vector<PII> a(m+1);
    for (int i = 1; i <= m; i ++ ) {
        cin >> a[i].x >> a[i].y;
    }
    function<bool(int)> check = [&](int x) -> bool {
        vector<int> g[n+1], d(n+1);
        for (int i = 1; i <= x; i ++ ) {
            g[a[i].x].push_back(a[i].y);
            d[a[i].y] ++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i ++ ) {
            if (d[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            if ((int)q.size() > 1) {
                return false;
            }
            int u = q.front(); q.pop();
            for (int v: g[u]) {
                if (--d[v] == 0) {
                    q.push(v);
                }
            }
        }
        return true;
    };
    int l = 1, r = m;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << (check(r) ? r : -1) << endl;
} 