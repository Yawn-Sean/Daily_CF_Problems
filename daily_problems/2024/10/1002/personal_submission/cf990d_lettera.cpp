#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    // 建图
    // n个点
    // a个连通块->b个连通块
    int n, a, b;
    cin >> n >> a >> b;
    int f = 1;
    vector<vector<int>> g(n, vector<int>(n));
    if (a > 1 && b == 1)
    {
        for (int i = 1; i <= n - a; i++)
        {
            g[i - 1][i] = 1;
        }
    }
    else if (b > 1 && a == 1)
    {
        vector<vector<int>> t(n, vector<int>(n, 1));
        for (int i = 1; i <= n - b; i++)
        {
            t[i - 1][i] = 0;
        }
        g = t;
    }
    else if (a == b && a == 1)
    {
        if (n == 2 || n == 3)
        {
            cout << "NO\n";
            return;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                g[i - 1][i] = 1;
            }
        }
    }
    else
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        g[i][i] = 0;
        for (int j = 0; j < i; j++)
        {
            g[i][j] = g[j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g[i][j];
        }
        cout << "\n";
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
