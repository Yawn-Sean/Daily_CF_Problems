int n;
string s, t;

void solve() {
    cin >> n;
    cin >> s >> t;
    vector<int> cnt(26);
    for (auto c : s) {
        cnt[c - 'a'] += 1;
    }
    for (auto c : t) {
        cnt[c - 'a'] += 1;
    }
    
    for (int i = 0; i < 26; i ++) {
        if (cnt[i] & 1) {
            cout << "No" << endl;
            return;
        }
    }
    vector<pii> res;
    for (int i = 0; i < n; i ++) {
        if (s[i] == t[i]) continue;
        for (int j = i + 1; j < n; j ++) {
            if (s[i] == s[j]) {
                swap(s[j], t[i]);
                res.emplace_back(j + 1, i + 1);
                break;
            }
            else if (s[i] == t[j]) {
                swap(s[j], t[j]);
                res.emplace_back(j + 1, j + 1);
                swap(s[j], t[i]);
                res.emplace_back(j + 1, i + 1);
                break;
            }
        }
    }
    cout << "Yes" << endl;
    cout << sz(res) << endl;
    for (auto p : res) {
        cout << p << endl;
    }
}