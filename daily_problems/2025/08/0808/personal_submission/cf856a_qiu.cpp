#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = -1e18;
typedef pair<int, int> PII;
const int mod = 1e9 + 7, N = 2 * 1e6 + 10;
bool vis[N];
void solve()
{
    memset(vis, 0, sizeof vis);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i <= 1000000; i++)
    {
        bool ok = true;
        for (auto v : a)
        {
            if (vis[v + i])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            b.push_back(i);

            for (auto v : a)
            {
                vis[v + i] = true;
            }
            if (b.size() >= n)
                break;
        }
    }
    if (b.size() == n)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " \n"[i == n - 1];
        }
    }
    else
    {
        cout << "No" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}