int n;
string s, t;

void solve() {
    cin >> n;
    cin >> s >> t;
    // 把前后相同的删去
    while (sz(s) and s.back() == t.back()) {
        s.pop_back();
        t.pop_back();
    }
    reverse(all(s));
    reverse(all(t));
    while (sz(s) and s.back() == t.back()) {
        s.pop_back();
        t.pop_back();
    }
    int len = sz(s);
    int res = 0;
    
    if (s.substr(0, len - 1) == t.substr(1)) res += 1;
    if (s.substr(1) == t.substr(0, len - 1)) res += 1;
    cout << res << endl;
}