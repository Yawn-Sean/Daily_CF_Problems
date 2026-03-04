void solve() {
    vector<int> a(52);
    for (int i = 0; i < 52; ++i) {
        cin >> a[i];
    }
    for (int k = 0; k < 8; ++k) {
        vector<int> c(52);
        for (int i = 0; i < 52; ++i) {
            if (i % 2 == 0) {
                c[i] = a[i / 2];
            } else {
                c[i] = a[i / 2 + 26];
            }
        }
        int c1 = 0;
        for (int i = 0; i < 26; ++i) {
            if (c[i] == 1) {
                ++c1;
            }
        }
        if (c1 == 4) {
            cout << "YES";
            return;
        }
        swap(a, c);
    }
    cout << "NO";
}
