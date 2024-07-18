/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-18 17:16 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123, MOD = 1000000007;

int main() {
    vector dp(N, vector (3000, 0)); 
    vector sum(3000, 0);
    dp[0][0] = 1;
    sum[0] = 1;
    for (int j = 1; j <= 25 * 100; j ++) {
        sum[j] = dp[0][j] + sum[j - 1];
        sum[j] %= MOD;
    }
    for (int i = 1; i <= 100; i ++) {
        for (int j = 0; j <= 25 * i; j ++) {
            if (j - 25 <= 0) dp[i][j]  = dp[i][j] + sum[j];
            else dp[i][j] = dp[i][j] + sum[j] - sum[j - 25 - 1];
            dp[i][j] %= MOD;
        }
        for (int j = 1; j <= 25 * 100; j ++) {
            sum[j] = dp[i][j] + sum[j - 1];
            sum[j] %= MOD;
        }
    }
    int t;
    cin >> t;
    while (t --) {
        char s[N];
        cin >> s + 1;
        int n = strlen(s + 1);
        int tot = 0;
        for (int i = 1; i <= n; i ++) {
            tot += s[i] - 'a';
        }
        cout << ((dp[n][tot] - 1) % MOD + MOD) % MOD << endl;
    }
    return 0;
}

/*

*/
