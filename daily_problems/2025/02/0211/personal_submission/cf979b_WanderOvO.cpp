int n, cnt[3][N], res[3];
string s[3];

void meibao() {
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++) {
            cnt[i][s[i][j] - 'A']++;
        }
        
        int mx = 0;
        for (int j = 0; j < 26; j++) {
            mx = max(mx, cnt[i][j]);
        }
        for (int j = 'a' - 'A'; j <= 'z' - 'A'; j++) {
            mx = max(mx, cnt[i][j]);
        }
        
        if (mx + n <= s[i].size()) {
            res[i] = mx + n;
        } else {
            if (mx == s[i].size() && n == 1) {
                res[i] = s[i].size() - 1;
            } else {
                res[i] = s[i].size();
            }
        }
    }

    if (res[0] > res[1] && res[0] > res[2]) {
        cout << "Kuro\n";
    } else if (res[0] < res[1] && res[2] < res[1]) {
        cout << "Shiro\n";
    } else if (res[0] < res[2] && res[1] < res[2]) {
        cout << "Katie\n";
    } else {
        cout << "Draw\n";
    }
}
