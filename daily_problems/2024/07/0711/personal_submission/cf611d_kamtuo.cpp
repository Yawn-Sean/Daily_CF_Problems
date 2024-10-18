/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-11 17:17 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 5123, MOD = 1000000007;

int dp[N][N], sum[N][N], len[N][N];
char s[N];
int n;

int main() {
    cin >> n >> (s + 1);
    dp[0][0] = 1;
    sum[0][0] = 1;
    for (int i = n; i; i --) {
        for (int j = n; j; j --) {
            if (s[i] == s[j]) len[i][j] = (len[i + 1][j + 1] + 1) % MOD;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j; j --) {
            int x = j, y = j - (i - j + 1);
            if (s[j] == '0') continue;
            if (y <= 0) dp[i][i - j + 1] += sum[j - 1][j - 1];
            else if (len[x][y] >= i - j + 1) dp[i][i - j + 1] += sum[j - 1][i - j];
            else if (s[x + len[x][y]] > s[y + len[x][y]]) dp[i][i - j + 1] += sum[j - 1][i - j + 1];
            else dp[i][i - j + 1] += sum[j - 1][i - j];
            dp[i][i - j + 1] %= MOD;
        }
        sum[i][0] = 0;
        for (int j = 1; j <= i; j ++) {
            sum[i][j] = sum[i][j - 1] + dp[i][j];
            sum[i][j] %= MOD;
        }
    }
    int ans = 0;
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= n; j ++) {
    //         cout << dp[i][j] << " \n"[j == n];
    //     }
    // }
    for (int i = 1; i <= n; i ++) {
        ans = ans + dp[n][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
/*

*/
