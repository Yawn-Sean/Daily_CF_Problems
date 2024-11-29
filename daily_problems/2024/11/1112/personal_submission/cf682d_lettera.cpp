#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    // dp[i][j]表示前i,j个字符最大匹配子串长度和
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int x = 1; x <= k; x++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i] == b[j])
                {
                    dp[i + 1][j + 1] = dp[i][j] + 1; // dp[i+1][j+1]最多比dp[i][j]大1
                }
            }
        }
        // 维护最大值
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i + 1][j + 1] = max({dp[i + 1][j + 1], dp[i][j + 1], dp[i + 1][j]});
            }
        }
    }
    cout << dp[n][m];
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
