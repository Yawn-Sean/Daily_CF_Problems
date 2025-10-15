#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
const int N = 5000 + 10, mod = 1e9 + 7;
int dp[N][N];
void solve()
{
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        dp[i][0] = 1;
        for (int j = 0; j < t.size(); j++)
        {
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
            if (s[i] == t[j])
            {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
                ans = (ans + dp[i][j]) % mod;
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
