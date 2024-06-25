int n;

void solve() {
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i ++) {
        c1 += (s1[i] == '1');
        c2 += (s2[i] == '1');
    }
    
    int res = inf;
    if (c1 == c2) {
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            ans += (s1[i] != s2[i]);
        }
        res = min(res, ans);
    }
    
    c1 = n - c1 + 1;
    if (c1 == c2) {
        int ans = 0, one = 0;
        for (int i = 0; i < n; i ++) {
            if (s1[i] == s2[i]) {
                ans += 1;
                if (s1[i] == '1') one = 1;
            }
        }
        res = min(res, ans + 1 - (one ? 1 : -1));
    }
    cout << (res == inf ? -1 : res) << endl;
}