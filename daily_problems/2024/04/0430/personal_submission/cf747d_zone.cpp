void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<PII> loc;

    for (int i = 1; i <= n; i ++ ) {
        if (a[i] < 0) {
            int j = i;
            while (j <= n && a[j] < 0) j ++;
            loc.emplace_back(i, j - 1);
            i = j;
        }
    }
    int ans = !loc.empty();
    if (ans) m -= loc[0].second - loc[0].first + 1;
    priority_queue<int> q;
    int s = loc.size();
    for (int i = 1; i < s; i ++ ) {
        m -= loc[i].second - loc[i - 1].second;
        q.push(loc[i].first - loc[i - 1].second - 1);
        while (m < 0 && !q.empty()) {
            // 反悔
            m += q.top();
            q.pop();
            ans += 2;
        }
        if (m < 0) break;
    }
    if (m < 0) ans = -1;
    else if (s > 0 && m < n - loc[s - 1].second) ans ++;
    cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solve();
    return 0;
}
