void solve() {
    int n, m;
    cin >> n >> m;
    vector<multiset<int>> a(n + 1);
    vector<int> dist(n + 1);
    for (int i = 0; i < m; i ++ ) {
        int x, y;
        cin >> x >> y;
        a[x].insert(y);
    }
    for (int i = 1; i <= n; i ++ ) {
        auto t = a[i].upper_bound(i);
        if (t == a[i].end()) t = a[i].begin();
        if (*t > i) dist[i] = *t - i;
        else dist[i] = *t + n - i;
    } 
    for (int i = 1; i <= n; i ++) {
        i64 ans = 0;
        for (int j = 1; j <= n; j ++ ) {
            i64 res = (j >= i ? j - i: j + n - i);
            int size = a[j].size();
            ans = max(ans, res + 1LL * n * (size - 1) + dist[j]);
        }
        cout << ans << " \n"[i == n];
    }
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solve();
    return 0;
}
