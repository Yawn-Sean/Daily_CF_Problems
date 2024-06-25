int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    
    int t = 0;
    for (int i = 0; i < sz(s); i ++) {
        if (s[i] == s[0]) t ++;
        else break;
    }
    
    if (t == sz(s)) {
        cout << n << endl;
        return;
    }
    
    ll res = (ll)(n - t) * n + t;
    int a = 0, b = 0;
    for (int i = t; i < sz(s); i ++) {
        if (s[i] == 'D') a ++;
        else b ++;
    }
    res -= (ll)a * b;
    cout << res << endl;
}