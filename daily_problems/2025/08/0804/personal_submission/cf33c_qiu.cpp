#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = -1e18;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
int ans;

void solve()
{
    int n;
    cin >> n;
    vector<int> f(n + 2, 0), g(n + 2, 0), a(n + 1, 0), maxnum(n + 1, INF);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i] += g[i - 1];
        f[i] += f[i - 1];
        if (a[i] > 0)
        {
            f[i] += a[i];
        }
        else
        {
            g[i] -= a[i];
        }
    }
    maxnum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        maxnum[i] = max(maxnum[i - 1] + a[i], g[i] - f[i]);
    }
    int ans = INF;
    int l = 0, r = 0;
    for (int i = n; i >= 1; i--)
    {
        ans = max(ans, maxnum[i] - l + r);
        if (a[i] > 0)
            l += a[i];
        else
            r -= a[i];
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}