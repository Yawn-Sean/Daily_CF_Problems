void solve() {
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<char, int> cnt;
    for (char c : s) {
        cnt[c]++;
    }
    if (cnt.size() == 1) {
        cout << "Impossible" << endl;
        return;
    }
    if (n % 2 == 1) {
        char c = s[0];
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (i != j && (s[i] != c || s[j] != c)) {
                cout << 2 << endl;
                return;
            }
        }
        cout << "Impossible" << endl;
        return;
    } else {
        int m = n;
        string t = s;
        while (m > 0 && m % 2 == 0) {
            reverse(t.begin(), t.begin() + m / 2);
            if (t != s) {
                cout << 1 << endl;
                return;
            }
            reverse(t.begin(), t.begin() + m / 2);
            m /= 2;
        }
        cout << 2 << endl;
    }
}