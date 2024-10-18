int n;
string s;

void solve() {
    cin >> n >> s;
    int it = 0;
    // 只需要暴力地把s扩展到n的长度
    int res = sz(s);
    for (int i = 0; i < n; i ++) {
        int len = (res - it - 1 + mod) % mod;
        int t = s[it] - '0' - 1;
        for (int j = 0; j < t and sz(s) <= n; j ++) {
            for (int k = it + 1; k < res and sz(s) <= n; k ++) {
                s += s[k];
            }
        }
        it += 1;
        res = (res + (ll)len * t) % mod;
    }
    
    cout << res << endl;
}