void Solve() {
    int a, b, mod;cin >> a >> b >> mod;
    a = min(a, (int)1e9 - 1);
    b = min(b, (int)1e9 - 1);
    if (b >= mod) {
        cout << "2\n";
    }
    else {
        int c = (int)1e9 % mod;
        for (int i = 1;i <= a && i < mod;i++) {
            int d = i % mod * c % mod;
            if (1 <= d && d < mod - b) {
                string s = to_string(i);
                while (s.size() < 9) s = '0' + s;
                return cout << 1 << ' ' << s << endl, void();
            }
        }
        cout << "2\n";
    }
}
