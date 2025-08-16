#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 1e9 + 7;

void solve()
{
    vector<int> dp(1024, 0);
    for (int i = 1; i <= 1000; i++)
    {
        int num = i;
        int cnt = 1;
        while (num > 1)
        {
            int t = 0;
            for (int j = 0; j <= 9; j++)
            {
                if (num >> j & 1)
                    t++;
            }
            num = t;
            cnt++;
        }
        dp[i] = cnt;
        // cout << i << ' ' << dp[i] << endl;
    }
    int mx = *max_element(dp.begin(), dp.end());
    vector<vector<int>> C(1010, vector<int>(1010, 0));
    C[0][0]=1;
    for (int i = 1; i <= 1000; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
            // if (i <= 5)
            // {
            //     cout << i << ' ' << j << ' ' << C[i][j] << endl;
            // }
        }
    }
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    if (k > mx)
    {
        cout << 0 << endl;
        return;
    }
    s = " " + s;
    int cnt = 0;
    vector<int> num(1024, 0);
    if (k == 0)
    {
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        // if(s[i]=='0' && i==n)num[cnt]++;
        if (s[i] == '0')
            continue;
        int len = n - i;
        for (int j = 0; j <= len; j++)
            num[cnt + j] = (num[cnt + j] + C[len][j]) % mod;
        cnt++;
    }
    num[cnt]++;
    num[1]--;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == k)
        {
            ans = (ans + num[i]) % mod;
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
