int n;
string s;

bool check(string& s, int i) {
    return (i - 1 >= 0 and s[i - 1] + 1 == s[i]) or (i + 1 < sz(s) and s[i + 1] + 1 == s[i]);
}
void solve() {
    cin >> n;
    cin >> s;
    char c = 'z';
    while (c >= 'a') {
        for (int i = 0; i < sz(s); i ++) {
            if (s[i] == c) {
                if (check(s, i)) {
                    s = s.substr(0, i) + s.substr(i + 1);
                    i = -1;
                }
            }
        }
        c --;
    }
    cout << (n - sz(s)) << endl;
}