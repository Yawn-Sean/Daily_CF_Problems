int n, m;
string s, t;

void solve() {
    cin >> s >> t;
    n = sz(s);
    m = sz(t);

    int c1 = 0, c2 = 0;
    for (auto c : s) {
        c1 += (c == '1');
    }
    for (auto c : t) {
        c2 += (c == '1');
    }
    
    cout << (c1 >= c2 or (c1 % 2 and c1 + 1 == c2) ? "YES" : "NO") << endl;
}