int n, m;
string s;

void solve() {
    cin >> n >> m;
    cin >> s;
    // s中不存在长于1的回文串 因此我们也只会产生长度为2 3的回文串
    if (m == 1) {
        cout << "NO" << endl;
        return;
    }
    if (m == 2) {
        if (n == 1) {
            if (s == "a") {
                cout << "b" << endl;
                return;
            }
            cout << "NO" << endl;
            return;
        }
        else {
            if (s == "ab") {
                cout << "ba" << endl;
                return;
            }
            cout << "NO" << endl;
            return;
        }
    }
    
    for (int i = n - 1; i >= 0; i --) {
        do {
            s[i] += 1;
        } while ((i - 1 >= 0 and s[i] == s[i - 1]) or (i - 2 >= 0 and s[i] == s[i - 2]));
        if (s[i] - 'a' + 1 <= m) {
            for (int j = i + 1; j < n; j ++) {
                while ((j - 1 >= 0 and s[j] == s[j - 1]) or (j - 2 >= 0 and s[j] == s[j - 2])) s[j] ++;
            }
            cout << s << endl;
            return;
        }
        s[i] = 'a';
    }
    cout << "NO" << endl;
}