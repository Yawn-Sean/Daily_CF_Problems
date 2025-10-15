/*
至多只能取 10 个不相交的串，并且是恰好取这么多
dp[i][j][k]: s 中前 i 个字符，强制以 i 结尾，t 中前 j 个字符，强制以 j 结尾
k 个不相交字符串，最大长度
- s[i] == t[j]:
  - i == 1 && j == 1, 和相等处理一样，dp[0][0][0] + 1
  - i == 1 || j == 1, 和不相等的处理一样
  - s[i - 1] == t[j - 1]: dp[i - 1][j - 1][k] + 1
  - s[i - 1] != t[j - 1] 或者即使相等但不和前面拼
    max(dp[<= i - 1][<= j - 1][k - 1]) + 1
- s[i] != t[j]: dp[i][j][k] = 0
答案：max(dp[i][j][cnt])
先枚举 k，每个 k 枚举完之后，统一更新一下前缀最大值
*/

int n, m, cnt;
string s, t;
int dp[N][N][M], max_dp[N][N];

void meibao() {
    cin >> n >> m >> cnt;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    for (int k = 1; k <= cnt; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i] == t[j]) {
                    if (i == 1 && j == 1) {
                        if (k == 1) {
                            dp[i][j][k] = 1;
                        }
                        continue;
                    } else if (i == 1 || j == 1) {
                        dp[i][j][k] = max_dp[i - 1][j - 1] + 1;
                        continue;
                    } 
                    if (s[i - 1] == t[j - 1]) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + 1);
                    }
                    dp[i][j][k] = max(dp[i][j][k], max_dp[i - 1][j - 1] + 1);
                } else {
                    dp[i][j][k] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                max_dp[i][j] = max({max_dp[i - 1][j], max_dp[i][j - 1], dp[i][j][k]});
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res = max(res, dp[i][j][cnt]);
        }
    }
    cout << res << "\n";
}
