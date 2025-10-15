/*
前 i 个字符分成 j 个回文串，至少改多少个字符
枚举最后一个回文串多长，假设长度为 len
dp[i][j] = min(dp[i - len][j - 1] + cost(i - len + 1, i))
如何快速计算 cost(l, r)
考虑使用另一个 DP
cost[l][l] 和 cost[l][l + 1] 很容易算出来
cost[l][r] 由 cost[l + 1][r - 1] 转移过来 
*/
 
int k, cost[M][M], dp[M][M], n, choices[M][M];
string s;
 
void meibao() {
    cin >> s;
    cin >> k;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        cost[i][i] = 0; 
        if (i + 1 <= n) {
            cost[i][i + 1] = (s[i] == s[i + 1] ? 0 : 1);
        }
    }
 
    for (int len = 3; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            cost[l][r] = cost[l + 1][r - 1] + (s[l] == s[r] ? 0 : 1);
        }
    }
 
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int len = 1; len <= i; len++) {
                int val = dp[i - len][j - 1] + cost[i - len + 1][i];
                if (val < dp[i][j]) {
                    dp[i][j] = val;
                    choices[i][j] = len;
                }
            }
        }
    }
 
    int res = INF;
    int cnt = 0;
    for (int j = 1; j <= k; j++) {
        if (res > dp[n][j]) {
            res = dp[n][j];
            cnt = j;
        }
    }
    if (res > INF / 2) {
        res = -1;
    }
    cout << res << "\n";
 
    vector<string> parts;
    int r = n;
    while (r > 0) {
        int len = choices[r][cnt];
        int l = r - len + 1;
        for (int p1 = l, p2 = r; p1 < p2; p1++, p2--) {
            if (s[p1] != s[p2]) {
                s[p1] = s[p2];
            }
        }
        parts.push_back(s.substr(l, len));
        r = l - 1;
        cnt--;
    }
    reverse(parts.begin(), parts.end());
    for (int i = 0; i < parts.size(); i++) {
        cout << parts[i];
        if (i + 1 < parts.size()) {
            cout << "+";
        }
    }
    cout << "\n";
}
 
