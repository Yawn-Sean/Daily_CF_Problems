#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n + 1);
    int mn1 = 1e9, mn2 = 1e9, mn3 = 1e9, mx1 = 0, mx2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        if (x <= mn1)
        {
            swap(mn2, mn3);
            swap(mn1, mn2);
            mn1 = x;
        }
        else if (x <= mn2)
        {
            swap(mn2, mn3);
            mn2 = x;
        }
        else if (x <= mn3)
        {
            mn3 = x;
        }
        if (x >= mx1)
        {
            mx2 = mx1;
            mx1 = x;
        }
        else if (x > mx2)
        {
            mx2 = x;
        }
    }
    int ans1 = mx1 + mx2 - mn1 - mn2;
    int ans2 = max(mx1 + mx2, mx1 + mn1 + h) - min(mn2 + mn3, mn1 + mn2 + h);
    if (ans1 < ans2)
    {
    	cout<<ans1<<"\n";
        for (int i = 1; i <= n; i++)
        {
            cout << 1 << " ";
        }
    }
    else
    {
    	cout<<ans2<<"\n";
        int f = 1;
        for (int i = 1; i <= n; i++)
        {
            if (f && a[i] == mn1)
            {
                f = 0;
                cout << 2 << " ";
                continue;
            }
            else
            {
                cout << 1 << " ";
            }
        }
    }
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
