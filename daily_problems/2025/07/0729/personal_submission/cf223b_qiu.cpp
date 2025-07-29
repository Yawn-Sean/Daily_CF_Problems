#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
typedef long long LL;
const int mod = 998244353;
const int N = 2e5 + 1, M = 350;

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = " " + s;
    t = " " + t;
    vector<int> vis(26, 0);
    for (int i = 1; i <= m; i++)
    {
        vis[t[i] - 'a'] = i;
    }
    vector<int> dp(n + 2, 1e9 + 10);
    int l = m;
    for (int i = n; i >= 1; i--)
    {
        dp[i] = min(dp[i + 1], l);
        if (s[i] == t[l] && l)
        {
            l--;
        }
        if (!vis[s[i] - 'a'])
        {
            cout << "No" << endl;
            return;
        }
    }
    if (l)
    {
        cout << "No" << endl;
        return;
    }
    vector<int> pre_dp(n + 1, -1e9);

    l = 0;
    vector<int> last_char(26, -1e9);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == t[l + 1])
        {
            l++;
            last_char[s[i] - 'a'] = l;
        }
        int pos = last_char[s[i] - 'a'];
        // cout << i << ' ' << pos << endl;
        if (pos < dp[i] || pos == 0)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
