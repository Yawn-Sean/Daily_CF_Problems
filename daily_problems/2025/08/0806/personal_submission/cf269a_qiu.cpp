#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = -1e18;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<PII> ve(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ve[i] = {a, b};
    }
    sort(ve.begin(), ve.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = ve[i];
        // cout << log(1) / log(4) << endl;
        int len = max((int)ceil(log(y) / log(4)), 1ll);
        ans = max(ans, x + len);
    }
    cout << ans << endl;
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