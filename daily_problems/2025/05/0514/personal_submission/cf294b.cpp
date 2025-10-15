#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;

/*
    这题的主要思路就是当厚度为k时能取到宽度的最大值
    这样的话当厚度唯一时就能让尽可能多的利用横放的空间
    当wsum-dp[i]<=i时表示当前横放书的总厚度刚好可以横放下可以横放的书
*/

void solve()
{
    int n = 0, tsum = 0, wsum = 0, k = 0;
    string s;
    cin >> n;
    vector<int> t(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> w[i];
        tsum += t[i];
        wsum += w[i];
    }
    vector<int> dp(210, -inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = tsum; j >= t[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - t[i]] + w[i]);
        }
    }

    for (int i = 1; i <= tsum; i++)
    {
        if (wsum - dp[i] <= i)
        {
            cout << i << endl;
            return;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
