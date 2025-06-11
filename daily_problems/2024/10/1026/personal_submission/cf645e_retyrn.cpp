int n, k;
string s;

void solve() {
    cin >> n >> k;
    cin >> s;
    int m = sz(s);
    
    vector<int> pos(k, -1);
    for (int i = 0; i < m; i ++) {
        pos[s[i] - 'a'] = i;
    }
    vector<int> id(k);
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        return pos[x] < pos[y];
    });
    
    vector<ll> dp(k, 0);
    ll tot = 0;
    
    for (int i = 0; i < m + n; i ++) {
        int u = (i < m ? s[i] - 'a' : id[(i - m) % k]);
        ll val = (tot - dp[u] + 1 + mod) % mod;
        dp[u] = (dp[u] + val) % mod;
        tot = (tot + val) % mod;
    }
    cout << (tot + 1) % mod << endl;
}