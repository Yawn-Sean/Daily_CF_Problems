#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;
int dp[2010][2010];
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }
    int ans = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= 2000; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= 2000; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
        // cout << dp[i][1] << ' ' << dp[i][2] << ' ' << dp[i][3] << endl;
    }
    if (k == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            int sum = 0, cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (g[i][j] == -1)
                    continue;
                cnt++;
                sum += g[i][j];
            }
            ans += sum * (cnt - 1);
        }
        // cout << ans << endl;
        cout << ans / dp[n][k] << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            int sum = 0, cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (g[i][j] <= 0)
                    continue;
                ans += g[i][j];
            }
        }

        cout << ans / n << endl;
    }
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
