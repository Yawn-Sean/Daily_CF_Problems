#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, p;
    cin >> n >> k >> p;

    vector<vector<int>> dp(k, vector<int>(p, - n * p));
    dp[0][0] = 0;
    int cur = 0, num;

    for (int i = 0; i < n - 1; i ++) {
        cin >> num;
        num %= p, cur += num;
        if (cur >= p) cur -= p;
        for (int x = k - 2; x >= 0; x --)
            for (int y = 0; y < p; y ++)
                dp[x+1][cur] = max(dp[x+1][cur], dp[x][y] + (cur - y + p) % p);
    }

    cin >> num;
    num %= p, cur += num;
    if (cur >= p) cur -= p;

    int ans = 0;

    for (int i = 0; i < p; i ++)
        ans = max(ans, dp[k-1][i] + (cur + p - i) % p);

    cout << ans << '\n';
    return 0;
}