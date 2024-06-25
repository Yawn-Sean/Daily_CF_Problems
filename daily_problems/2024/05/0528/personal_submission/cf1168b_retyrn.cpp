int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    
    int r = n;
    ll res = 0;
    for (int i = n - 1; i >= 0; i --) {
        for (int k = 1; i + k + k < n; k ++) {
            if (s[i] == s[i + k] and s[i] == s[i + k + k]) {
                r = min(i + k + k, r);
                break;
            }
        }
        res += n - r;
    }
    cout << res << endl;
}