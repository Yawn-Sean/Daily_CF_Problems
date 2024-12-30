int n;
string s;
void solve() {
    cin >> n;
    cin >> s;
    if (s[0] == '0') {
        cout << 0 << endl;
        return;
    }
    
    // 预处理lcp
    vector<vector<int>> lcp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i --) {
        for (int j = n - 1; j > i; j --) {
            if (s[i] == s[j]) {
                lcp[i][j] = 1 + (i + 1 < n and j + 1 < n ? lcp[i + 1][j + 1] : 0);
            }
        }
    }
    
    auto check = [&](int s1, int s2, int len) {
        if (lcp[s1][s2] >= len) return false;
        auto t = lcp[s1][s2];
        return s[s1 + t] < s[s2 + t];
    };
    
    vector<vector<int>> f(n, vector<int>(n + 1, 0));
    vector<vector<int>> g(n, vector<int>(n + 1, 0));
    // f[i][j] 最后一个字符串末尾为s[i] 长度为j的 合法方案数
    
    for (int i = 0; i < n; i ++) {
        f[i][i + 1] = 1;
        // 枚举长度
        for (int len = 1; len <= i; len ++) {
            // 前导0
            if (s[i - len + 1] == '0') continue;
            
            f[i][len] = (f[i][len] + g[i - len][len - 1]) % mod;
            // 相同长度 s[i-len+1:i] s[i-len*2+1:i-len]
            int j = i - len * 2 + 1;
            if (j >= 0 and check(j, j + len, len)) {
                f[i][len] = (f[i][len] + f[i - len][len]) % mod;
            }
        }
        for (int len = 1; len <= n; len ++) {
            g[i][len] = (g[i][len - 1] + f[i][len]) % mod;
        }
    }
    
    int res = 0;
    
    for (int len = 1; len <= n; len ++) {
        res = (res + f[n-1][len]) % mod;
    }
    cout << res << endl;
}