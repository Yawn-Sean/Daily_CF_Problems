int n;

void solve() {
    // 一个字符串里面不可以有两个一样的字母
    cin >> n;
    vector<string> s(n);
    vector<bool> st(26, false);
    for (int i = 0; i < n; i ++) {
        cin >> s[i];
        vector<int> cnt(26);
        for (auto c : s[i]) {
            if (cnt[c - 'a']) {
                cout << "NO" << endl;
                return;
            }
            cnt[c - 'a'] = 1;
            st[c - 'a'] = true;
        }
    }
    
    // 相邻的两个字母的关系
    vector<vector<int>> cnt(26, vector<int>(26));
    
    for (auto& ss : s) {
        int m = sz(ss);
        for (int i = 0; i + 1 < m; i ++) {
            int u = ss[i] - 'a', v = ss[i + 1] - 'a';
            cnt[u][v] += 1;
        }
    }
    vector<int> g(26, -1);
    vector<int> d(26);
    for (int i = 0; i < 26; i ++) {
        int t = 0;
        int last = -1;
        for (int j = 0; j < 26; j ++) {
            if (cnt[i][j] > 0) {
                t += 1;
                last = j;
            }
        }
        if (t > 1) {
            cout << "NO" << endl;
            return;
        }
        if (last >= 0) {
            g[i] = last;
            d[last] += 1;
        }
            
        t = 0;
        for (int j = 0; j < 26; j ++) {
            if (cnt[j][i] > 0) {
                t += 1;
            }
        }
        if (t > 1) {
            cout << "NO" << endl;
            return;
        }
    }
    
    string res;
    for (int i = 0; i < 26; i ++) {
        if (st[i] and d[i] == 0) {
            int u = i;
            while (u >= 0) {
                res += char('a' + u);
                st[u] = false;
                u = g[u];
            }
        }
    }
    // 环
    for (int i = 0; i < 26; i ++) {
        if (st[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << res << endl;
}