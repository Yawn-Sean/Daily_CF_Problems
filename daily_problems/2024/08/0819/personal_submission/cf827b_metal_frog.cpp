void solve() {
    int n, k;
    cin >> n >> k;
    vector<pii> edges;
    vector<int> prev;
    int inner = n - k, it = 2;
    prev.push_back(1);
    vector<int> cnt(n + 1), dep(n + 1);
    while (it <= inner) {
        vector<int> nextLevel;
        for (int i = 0; i < k && it <= inner; i++, it++) {
            nextLevel.push_back(it);
            int u = prev[i % sz(prev)];
            edges.emplace_back(u, it);
            cnt[u]++; cnt[it]++;
            dep[it] = dep[u] + 1;
        }
        prev = nextLevel;
    }
    prev.clear();
    for (int i = 1; i <= n - k; i++) {
        if (cnt[i] < 2) {
            prev.push_back(i);
        }
    }
    for (int i = n - k + 1, it = 0; i <= n; i++, it++) {
        int u = prev[it % sz(prev)];
        edges.emplace_back(i, u);
        dep[i] = dep[u] + 1;
    }
    sort(dep.begin(), dep.end());
    reverse(dep.begin(), dep.end());
    int ans = dep[0] + dep[1];
    if (n - k == 2) ans = 3;
    cout << ans << "\n";
    for (auto [u, v] : edges) {
        cout << u << " " << v << "\n";
    }
}
