#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;
// 对于第i个数，我们考虑j
int dp[N][12];
int sum[N][12];
void solve()
{
    int n, k;
    cin >> n >> k;
    dp[0][0] = sum[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        sum[i][0] = 1;
        for (int j = 1; j <= k; j++)
        {

            dp[i][j] = (sum[i - 1][j - 1]) % mod;
            if (i > 2 && i != n)
            {
                dp[i][j] = (dp[i][j] - dp[i - 2][j - 1] + mod) % mod;
            }
            sum[i][j] = sum[i - 1][j] + dp[i][j];
        }
        dp[i][k + 1] = (dp[i][k + 1] + sum[i - 1][k] + sum[i - 1][k + 1]) % mod;
        if (i > 2 && i != n)
        {
            dp[i][k + 1] = (dp[i][k + 1] - dp[i - 2][k] - dp[i - 2][k + 1] + 2 * mod) % mod;
        }
        sum[i][k + 1] = (sum[i - 1][k + 1] + dp[i][k + 1]) % mod;
    }
    cout << (dp[n][k] + dp[n][k + 1]) % mod << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;

    // cin >> T;
    while (T--)
        solve();
    return 0;
}
