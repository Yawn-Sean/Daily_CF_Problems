constexpr int P = 1000000007;
using Z = MInt<P>;

void solve() {
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1), fa(n + 1), deg(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        if (!(l[i] == 0 && r[i] == 0)) {
            deg[i] = 2;
            fa[l[i]] = i;
            fa[r[i]] = i;
        }
    }
    vector<Z> up(n + 5);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            up[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (fa[u] == 0) {
            continue;
        }
        deg[fa[u]]--;
        if (deg[fa[u]] == 0) {
            up[fa[u]] = 3 + up[l[fa[u]]] + up[r[fa[u]]];
            q.push(fa[u]);
        }
    }
    vector<Z> dp(n + 5);
    dp[1] = up[1];

    auto dfs = [&](auto& dfs, int u) {
        if (l[u] == 0 && r[u] == 0) {
            return;
        }
        dp[l[u]] = dp[u] + up[l[u]];
        dp[r[u]] = dp[u] + up[r[u]];
        dfs(dfs, l[u]);
        dfs(dfs, r[u]);
    };

    dfs(dfs, 1);
    for (int i = 1; i <= n; i++) {
        cout << dp[i].val() << " \n"[i == n];
    }
}
