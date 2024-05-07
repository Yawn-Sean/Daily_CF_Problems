void Solve() {
    int cnt[4] = { 0,0,0,0 };
    cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];
    for (int i = 0;i < 4;i++) cnt[i]--;
    int n = 50;
    vector<string> s(n + 1);
    vector<vector<int>> bel(n + 1, vector<int>(n + 1));
    for (int i = 1;i <= 50;i++) {
        s[i] = ' ';
        for (int j = 1;j <= 50;j++) {
            if (i <= 25) {
                if (j <= 25) s[i] += 'A', bel[i][j] = 0;
                else s[i] += 'B', bel[i][j] = 1;
            }
            else {
                if (j <= 25) s[i] += 'C', bel[i][j] = 2;
                else s[i] += 'D', bel[i][j] = 3;
            }
        }
    }
    vector<vector<int>> vis(n + 1, vector<int>(n + 1));
    for (int c = 0;c < 4;c++) {
        for (auto sti : { 2,27 }) {
            for (auto stj : { 2,27 }) {
                for (int i = sti;i <= sti + 22;i += 2) {
                    for (int j = stj;j <= stj + 22;j += 2) {
                        if (!cnt[c]) {
                            goto jieshu;
                        }
                        if (bel[i][j] != c && !vis[i][j]) {
                            s[i][j] = c + 'A';
                            vis[i][j] = 1;
                            cnt[c]--;
                        }
                    }
                }
                jieshu : 111;
            }
        }
    }
    cout << "50 50\n";
    for (int i = 1;i <= n;i++) cout << s[i].substr(1) << endl;
}
