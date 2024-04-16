void solve() {
    int n;
    cin >> n;
    vector<int> siz(maxs * 3);
    vector<int> cost(maxs * 3);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        siz[x]++;
    }
    int root = -1;
    auto dfs1 = [&](auto self, int x) {
        if (x >= maxs) return;
        self(self, x * 2);
        self(self, x * 2 + 1);
        siz[x] += siz[x * 2] + siz[x * 2 + 1];
        cost[x] = cost[x * 2] + cost[x * 2 + 1] + siz[x * 2] + siz[x * 2 + 1];
 
        if (siz[x] == n && root == -1) {
            root = x;
        }
    };
 
//    debug(root, n);
 
    dfs1(dfs1, 1);
    int ans = cost[root];
//    for (int i = 1; i <= 10; i++) {
//        cerr << i << " " << siz[i] << " " << cost[i] << endl;
//    }
    function<void(int, int)> dfs2 = [&](int x, int cost) {
        ans = min(ans, cost);
        if (2 * x < maxs)
            dfs2(x * 2, cost - siz[x * 2] + n - siz[x * 2]);
    };
    dfs2(root, ans);
    cout << ans << endl;
}
