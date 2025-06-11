int n, m;
string s;

void solve() {
    cin >> n;
    cin >> s;
    
    vector<vector<int>> f(26, vector<int>(n + 1, inf));
    vector<int> cnt(26);
    for (int i = 0; i < n; i ++) {
        fill(all(cnt), 0);
        for (int j = i; j < n; j ++) {
            int len = j - i + 1;
            cnt[s[j] - 'a'] += 1;
            for (int k = 0; k < 26; k ++) {
                auto need = len - cnt[k];
                chmin(f[k][len], need);
            }
        }
    }
    
    cin >> m;
    while (m --) {
        int x;
        string ss;
        cin >> x >> ss;
        int u = ss[0] - 'a';
        if (x >= f[u][n]) {
            cout << n << endl;
            continue;
        }
        int l = 1, r = n;
        while (l < r) {
            auto mid = (l + r + 1) >> 1;
            if (f[u][mid] > x) r = mid - 1;
            else l = mid;
        }
        
        cout << l << endl;
    }
}