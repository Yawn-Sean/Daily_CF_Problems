#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;
const int N = 1e6 + 10;
void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans(n);
    int sum = 0;
    int cnt = n - a - b;
    int l;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (cnt == 1 && b == 0)
    {
        cout << -1 << endl;
        return;
    }
    // else if (cnt == 1 && b)
    // {

    // }
    if (b == 0)
    {
        l = 1;
        for (int i = 0; i < n; i++)
        {
            if (i < n - a)
                ans[i] = l;
            else
                ans[i] = ++l;
        }
    }
    else
    {

        l = 1;
        ans[0] = 1;
        for (int i = 1; i <= b; i++)
        {
            ans[i] = l + 1;
            l += l + 1;
        }
        l = (l + 1) / 2 + 1;
        for (int i = b + 1; i <= b + a; i++)
        {
            ans[i] = l;
            l = l + 1;
        }
        for (int i = a + b + 1; i < n; i++)
        {
            ans[i] = l - 1;
        }
    }
    int mx = *max_element(ans.begin(), ans.end());
    if (mx > 50000)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
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