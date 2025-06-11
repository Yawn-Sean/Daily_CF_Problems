/*
dp[i][j][cnt]: 前 i 个字符，第 i 个字符为 j，总共改变了 cnt 个字符的最大价值
dp[i][j][cnt] = dp[i - 1][ch][cnt] + c[ch][j]，如果使用原本的字符
dp[i][j][cnt] = dp[i - 1][ch][cnt - 1] + c[ch][j]，如果使用改动的字符
*/

int dp[110][27][110], n, m, k, c[27][27];
string s;

void meibao() {
    cin >> s >> k >> m;
    n = s.size();
    s = " " + s;
    while (m--) {
        string s1, s2;
        int val;
        cin >> s1 >> s2 >> val;
        c[s1[0] - 'a'][s2[0] - 'a'] = val;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            for (int cnt = 0; cnt <= k; cnt++) {
                dp[i][j][cnt] = -INF;
            }
        }
    }

    dp[1][s[1] - 'a'][0] = 0;
    for (int j = 0; j < 26; j++) {
        if (j != s[1] - 'a') {
            dp[1][j][1] = 0;
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            for (int cnt = 0; cnt <= min(i, k); cnt++) {
                for (int ch = 0; ch < 26; ch++) {
                    if (j == s[i] - 'a') {
                        dp[i][j][cnt] = max(dp[i][j][cnt], dp[i - 1][ch][cnt] + c[ch][j]); 
                    } else {
                        if (cnt > 0) {
                            dp[i][j][cnt] = max(dp[i][j][cnt], dp[i - 1][ch][cnt - 1] + c[ch][j]);
                        }
                    } 
                }
            }
        }
    }

    int res = -INF;
    for (int j = 0; j < 26; j++) {
        for (int cnt = 0; cnt <= k; cnt++) {
            res = max(res, dp[n][j][cnt]);
        }
    }
    cout << res << "\n";
}   
