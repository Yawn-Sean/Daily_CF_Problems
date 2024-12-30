int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    int res = 0;
    
    for (int i = 0; i < n; i ++) {
        int r = 0, cnt = 0;
        for (int j = i; j < n; j ++) {
            if (s[j] == '(') cnt ++;
            else if (s[j] == ')') cnt --;
            else {
                // 先当)
                r += 1;
                cnt -= 1;
            }
            while (cnt < 0 and r > 0) {
                cnt += 2;
                r -= 1;
            }
            if (cnt == 0) res += 1;
            else if (cnt < 0 and r == 0) break;
        }
    }
    cout << res << endl;
}