const int N = 2e5 + 7;
int cnt[26][N];

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i <= n; i++) {
        cnt[s[i - 1] - 'a'][i]++;
        for (int c = 0; c < 26; c++) {
            cnt[c][i] += cnt[c][i - 1];
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "Yes\n";
            continue;
        }
        int kind = 0;
        for (int c = 0; c < 26; c++) {
            if (cnt[c][r] - cnt[c][l - 1] > 0) kind++;
        }
        if (s[l - 1] == s[r - 1]) {
            if (kind > 2) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            cout << "Yes\n";
        }
    }   
}
