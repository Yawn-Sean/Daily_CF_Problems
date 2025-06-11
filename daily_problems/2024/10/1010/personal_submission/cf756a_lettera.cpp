#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int n, ans = 1;
    cin >> n;
    vector<int> a(n), p(n), vis(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        ans ^= (p[i] & 1);
    }
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            f++;
            ans++;
            for (int j = i; !vis[j]; j = a[j])
            {
                vis[j] = 1;
            }
        }
    }
    if (f == 1)
    {
        ans--;
    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
