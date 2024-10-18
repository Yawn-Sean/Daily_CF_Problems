#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ll long long
#define pii pair<int, int>

void solve()
{
    const int mo = 1e9 + 7;
    auto mypow = [&](int x, int y)
    {
        int res = 1;
        while (y)
        {
            if (y & 1)
                res = res * x % mo;
            y >>= 1;
            x = x * x % mo;
        }
        return res;
    };
    auto ni = [&](int x)
    {
        return mypow(x, mo - 2);
    };
    int n, m, g;
    cin >> n >> m >> g;
    vector<int> pre(n + m + 1, 1);
    for (int i = 1; i <= n + m; i++)
    {
        pre[i] = pre[i - 1] * i % mo;
    }

    auto C = [&](int x, int y)
    {
        if (x > y)
            return 0ll;
        return pre[y] * ni(pre[x]) % mo * ni(pre[y - x]) % mo;
    };

    int sum = C(n, n + m);
    int ans0 = 0;

    if (m == 0)
    {
        int ans0 = n % 2;
        cout << (g == 1 ? 1 - ans0 : ans0) << endl;
        return;
    }
    if (m == 1)
    {
        int sum = n + m;
        int ans0 = (n + m) / 2 + (sum % 2 == 0), ans1 = sum - ans0;
        // 长度为偶数，尾部0...1 会记作0而不是1
        if (g == 0)
            cout << ans0 << endl;
        else
            cout << ans1 << endl;
        return;
    }
    for (int k = 0; k <= n + m; k++)
    {
        if (n - 2 * k < 0 || n + m - 1 - 2 * k <= 0)
            break;
        int x = n - 2 * k, y = n + m - 1 - 2 * k;
        // cout << x << ' ' << y << endl;
        ans0 = (ans0 + C(n - 2 * k, n + m - 1 - 2 * k)) % mo;
    }
    if (g == 1)
        cout << ((sum - ans0) % mo + mo) % mo << endl;
    else
        cout << ans0 << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
    {
        solve();
    }
}
