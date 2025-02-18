void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vec<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    vec<int> dp(k + 1);
    for (int i = 0; i < n; i++) {
        vec<int> pos;
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] == '1') pos.push_back(j);
        }

        int m = pos.size();
        if (m > 0) {
            vec<int> ndp(k + 1, 0);
            vec<int> cost(m + 1);
            int tot = pos.back() - pos.front() + 1;

            ans += tot;
            cost[m] = tot;

            for (int l = 0; l < m; l++) {
                for (int r = l; r < m; r++) {
                    chmax(cost[m - (r - l + 1)], tot - (pos[r] - pos[l] + 1));
                }
            }

            for (int x = 0; x <= k; x++) {
                for (int y = 0; y <= m; y++) {
                    if (x + y > k) break;
                    chmax(ndp[x + y], dp[x] + cost[y]);
                }
            }
            dp = ndp;
        }
    }

    cout << ans - dp[k] << '\n';
}
