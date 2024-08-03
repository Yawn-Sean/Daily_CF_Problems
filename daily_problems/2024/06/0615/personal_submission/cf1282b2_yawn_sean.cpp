#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, p, k;
        cin >> n >> p >> k;
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i ++)
            cin >> dp[i];
        
        sort(dp.begin() + 1, dp.end());
        for (int i = 1; i < k; i ++)
            dp[i] += dp[i-1];
        for (int i = k; i <= n; i ++)
            dp[i] += dp[i-k];
        
        int ans = 0;
        for (int i = n; i >= 0; i --)
            if (dp[i] <= p) {
                ans = i;
                break;
            }
        cout << ans << '\n';
    }

    return 0;
}