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
    vector<int> a(n + 1, 0), p(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        a[t] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        p[i] = -a[b];
    }
    vector<int> f;
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(f.begin(), f.end(), p[i]) - f.begin();
        if (pos == f.size())
        {
            f.push_back(p[i]);
        }
        else
            f[pos] = p[i];
    }
    cout << f.size() << endl;
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