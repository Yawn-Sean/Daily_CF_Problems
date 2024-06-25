int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    vector<int> cnt(26, 0);
    for (auto c : s) {
        cnt[c - 'a'] += 1;
    }
    
    for (int i = 0; i < 26; i ++) {
        if (cnt[i] >= 100) {
            cout << string(100, 'a' + i) << endl;
            return;
        }
    }
    
    // 总长度小于2600 可以n^2
    vector<vector<int>> f(n, vector<int>(n, 0));
    // f[i][j] [l, r]的最长的回文子序列长度
    for (int i = 0; i < n; i ++) {
        f[i][i] = 1;
    }
    for (int len = 2; len <= n; len ++) {
        for (int i = 0; i + len - 1 < n; i ++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                f[i][j] = f[i+1][j-1] + 2;
            }
            else {
                f[i][j] = max(f[i+1][j], f[i][j-1]);
            }
        }
    }
    
    string res;
    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] == s[r]) {
            res.push_back(s[l]);
            l ++, r --;
        }
        else {
            if (f[l][r] == f[l+1][r]) l += 1;
            else r -= 1;
        }
    }
    if (sz(res) >= 50) {
        res = res.substr(0, 50);
        cout << res;
        reverse(all(res));
        cout << res << endl;
        return;
    }
    cout << res;
    if (l == r) res += s[l];
    reverse(all(res));
    cout << res << endl;
}