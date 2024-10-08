#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 #define int ll
void solve()
{
    ll n;
    cin >> n;
    vector<ll> ans;
    for (int i = 0; i < 60; i++)
    {
        ll c = ((1ll << i) - 1);
        ll l = 0, r = min<ll>(2E9, n / max(c, 1ll));
        ll mid;
        while (l < r)
        {
            mid = l + (r - l + 1) / 2;
            if ((mid * (mid - 1) / 2 + c * mid <= n))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        mid = l;
        if (mid * (mid - 1) / 2 + c* mid == n && mid % 2)
        {
            ans.push_back((c+1)* mid);
        }
    }
    if (ans.size())
    {
        for (auto x : ans)
        {
            cout << x << "\n";
        }
    }
    else
    {
        cout << -1 << "\n";
    }
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
