#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i - 1];
        m += a[i - 1];
    }
    sort(a.begin(), a.end());
    vector<int> dp(5010, 0);
    dp[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 5000; j >= 0; j--)
        {
            int val = min(j + a[i], 5000ll);
            dp[val] = (dp[val] + dp[j]) % mod;
            if (a[i] >= j)
                ans = (ans + (a[i] * dp[j]) % mod) % mod;
            else
            {
                ans = (ans + ((val + 1) / 2 * dp[j]) % mod) % mod;
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while (T--)
        solve();
    return 0;
}
