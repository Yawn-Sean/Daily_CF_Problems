/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-01 11:23 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123;

int dp[N][N];
int num[N];
int s[N];

#if !KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t --) {
        int n, m;
        cin >> n >> m;
        int bigbit = 0;
        for (int i = 0; i < 31; i ++) {
            if ((1 << i) <= n) bigbit = i;
        }
        debug("bigbit:", bigbit);
        for (int i = 0; i < bigbit; i ++) {
            num[i + 1] = ((1 << (i + 1)) - (1 << i)) % m;
            s[i + 1] = num[i + 1] % m + s[i] % m;
            s[i + 1] %= m;
        }
        memset(dp, 0, sizeof dp);
        num[bigbit + 1] = n - (1 << bigbit) + 1;
        num[bigbit + 1] %= m;
        debug("num[big + 1]:", num[bigbit + 1]);
        int ans = 0;
        for (int i = 0; i <= bigbit; i ++) dp[1][i] = num[i + 1], ans += dp[1][i], ans %= m;
        for (int i = 2; i <= bigbit + 1; i ++) {
            for (int j = 0; j <= bigbit; j ++) {
                for (int k = 0; k < j; k ++) {
                    dp[i][j] = (1ll * dp[i - 1][k] * num[j + 1] % m + dp[i][j]) % m;
                }
                ans += dp[i][j];
                ans %= m;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

#endif

/*

*/
