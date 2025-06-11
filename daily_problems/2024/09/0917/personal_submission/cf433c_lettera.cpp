#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    // 考虑merge(x,y)后sum的变化
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<vector<int>> c(n + 1);
    ll ans = 0, res = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        ans += i > 0 ? abs(a[i] - a[i - 1]) : 0;
        if (i > 0 && a[i] != a[i - 1])
        {
            c[a[i]].push_back(a[i - 1]);
            c[a[i - 1]].push_back(a[i]);
        }
    }
    res = ans;
    for (int i = 1; i <= n; i++)
    {
        if (c[i].size())
        {
            sort(c[i].begin(), c[i].end());
            int len = c[i].size();
            int mid = c[i][len / 2];
            ll sum1 = 0, sum2 = 0;
            for (int j = 0; j < len; j++)
            {
                sum1 += abs(c[i][j] - i);
                sum2 += abs(c[i][j] - mid);
            }
            ans = min(ans, res - sum1 + sum2);
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
