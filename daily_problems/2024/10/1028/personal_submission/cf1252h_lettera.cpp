#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
bool cmp(array<int, 2> a, array<int, 2> b)
{
    return a[0] > b[0];
}
void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    vector<array<ll, 2>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        if (a[i][0] > a[i][1])
        {
            swap(a[i][0], a[i][1]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, a[i][0] * a[i][1]);
    }
    sort(a.begin() + 1, a.end(), cmp);
    ll mx = 0;
    for (int i = 1; i <= n; i++)
    {

        if (i > 1)
        {
            ans = max(ans, 2ll * min(mx, a[i][1]) * a[i][0]);
        }
        mx = max(mx, a[i][1]);
    }
    cout << ans / 2;
    if (ans % 2)
    {
        cout << ".5";
    }
    else
    {
        cout << ".0";
    }
    cout << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
