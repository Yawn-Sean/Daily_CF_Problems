int n, m;
string s;

void solve() {
    cin >> n >> s >> m;
    
    vector<int> ca(n + 1), cb(n + 1);
    vector<int> cnt(n + 1);
    
    for (int i = 1; i <= n; i ++) {
        cnt[i] = cnt[i - 1] + (s[i - 1] == '?');
    }
    
    for (int i = n - 1; i >= 0; i --) {
        ca[i] = (s[i] != 'b' ? cb[i + 1] + 1 : 0);
        cb[i] = (s[i] != 'a' ? ca[i + 1] + 1 : 0);
    }
    
    vector<pii> dp(n + 1, mpr(0, 0));
    for (int i = 0; i < n; i ++) {
        chmax(dp[i + 1], dp[i]);
        if (ca[i] >= m) {
            int val = dp[i].fi + 1, need = dp[i].se - (cnt[i + m] - cnt[i]);
            chmax(dp[i + m], mpr(val, need));
        }
    }
    cout << -dp[n].se << endl;
}