int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    vector<int> l(maxn, -1), r(maxn, -1);
    for (int i = 0; i < n; i ++) {
        int x = a[i];
        if (l[x] == -1) l[x] = i;
        r[x] = i;
    }    
    vector<int> cnt(maxn, 0);
    vector<int> dp(n + 1);
    
    for (int i = 0; i < n; i ++) {
        chmax(dp[i + 1], dp[i]);
        int right = 0, ans = 0;
        fill(all(cnt), 0);
        for (int j = i; j < n; j ++) {
            if (l[a[j]] < i) break;
            if (++ cnt[a[j]] == 1) ans ^= a[j];
            chmax(right, r[a[j]]);
            if (right == j) {
                chmax(dp[j + 1], dp[i] + ans);
            }
        }
    }
    cout << dp[n] << endl;
}