void solve() {
    int n, m;
    cin >> n >> m;
    int max_cnt = 0;
    vector<vector<i64>> cost(m + 1);
    for (int i = 1; i <= n; i ++ ) {
        int a, b;
        cin >> a >> b;
        cost[a].push_back(b);
    }
    for (int i = 2; i <= m; i ++ ) {
        sort(cost[i].begin(), cost[i].end(), [&](i64 a, i64 b) {return a > b;});
        max_cnt = max(max_cnt, (int)cost[i].size());
    }
    i64 ans = INF;
    for (int fin = max(1, (int)cost[1].size()); fin <= max((int)cost[1].size(), max_cnt + 1); fin ++ ) {
        i64 res = 0;
        int cur = cost[1].size();
        priority_queue<i64, vector<i64>, greater<i64>> q;
        for (int i = 2; i <= m; i ++ ) {
            int t = cost[i].size();
            for (int j = 0; j < min(t, fin - 1); j ++ ) q.push(cost[i][j]);
            for (int j = min(t, fin - 1); j < t; j ++ ) res += cost[i][j], cur ++;
        }
        while (cur < fin && !q.empty()) {
            res += q.top();
            q.pop();
            cur ++;
        }
        if (cur >= fin) ans = min(ans, res);
    }
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solve();
    return 0;
}
