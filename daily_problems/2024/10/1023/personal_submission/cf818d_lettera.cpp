#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int n, A;
    cin >> n >> A;
    vector<int> a(n + 1);
    int M = 1E6 + 5;
    vector<vector<int>> c(M);
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {

        if (a[i] != A && c[a[i]].size() >= c[A].size())
        {
            int f = 1;
            for (int j = 0; j < c[A].size(); j++)
            {
                if (c[a[i]][j] > c[A][j])
                {
                    f = 0;
                    break;
                }
            }
            if (f)
            {
                cout << a[i] << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
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
