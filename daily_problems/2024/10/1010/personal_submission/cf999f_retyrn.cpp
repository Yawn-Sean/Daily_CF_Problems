int n, k;

void solve() {
    cin >> n >> k;
    vector<int> cnt(maxn);
    for (int i = 0; i < n * k; i ++) {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    
    vector<int> cf(maxn);
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        cf[x] += 1;
    }
    vector<int> h(k + 1);
    for (int i = 1; i <= k; i ++) {
        cin >> h[i];
    }
    
    vector<vector<ll>> dp(n + 1, vector<ll>(n * k + 1));
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= n * k; j ++) {
            // 枚举最后一个人拿了几张想要的
            for (int l = 0; l <= k and l <= j; l ++) {
                chmax(dp[i][j], dp[i-1][j-l] + h[l]);
            }
        }
    }
    
    ll res = 0;
    for (int i = 1; i <= 100000; i ++) {
        if (cf[i] == 0) continue;
        res += dp[cf[i]][cnt[i]];
    }
    
    cout << res << endl;
}