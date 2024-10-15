int a, b, mod;

string get(int x) {
    string s = to_string(x);
    reverse(all(s));
    while (sz(s) < 9) s += '0';
    reverse(all(s));
    return s;
}
void solve() {
    cin >> a >> b >> mod;
    for (int i = 0; i <= a and i <= mod; i ++) {
        int t = (mod - (ll)i * 1000000000ll % mod) % mod;
        if (t > b) {
            cout << 1 << ' ' << get(i) << endl;
            return;
        }
    }
    cout << 2 << endl;
}