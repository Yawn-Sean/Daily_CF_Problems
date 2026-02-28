void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> groups(n + 1);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        groups[y].push_back(x);
    }
    i64 res = 0, cur = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<i64> inc(n + 1);
    for (int y = n; y >= 0; y--) {
        for (int x: groups[y]) {
            pq.push(x);
            cur += x;
        }
        while (pq.size() > y + 1) {
            cur -= pq.top();
            pq.pop();
        }
        chmax(res, cur);
        inc[y] = cur;
        if (pq.size() == y + 1) {
            inc[y] -= pq.top();
        }
    }
    for (int y = 1; y <= n; y++) {
        chmax(inc[y], inc[y - 1]);
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << max(res, inc[y] + x) << " \n"[i == q - 1];
    }
}
