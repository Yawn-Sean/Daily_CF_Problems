#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n, 0);
    vector<PII> num;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i >= 1)
        {
            num.push_back({a[i] - a[i - 1], i - 1});
        }
    }
    sort(num.begin(), num.end());
    vector<int> d(m), f(k);
    for (int i = 0; i < m; i++)
        cin >> d[i];
    for (int i = 0; i < k; i++)
        cin >> f[i];
    sort(f.begin(), f.end());
    int mid = num[n - 2].second;
    int l = a[mid], r = a[mid + 1];
    mid = (a[mid] + a[mid + 1]) / 2;
    int ans = num[n - 2].first;
    for (int i = 0; i < m; i++)
    {
        int x = mid - d[i];
        auto pos = upper_bound(f.begin(), f.end(), x);
        if (pos == f.end())
        {
            int t = f[pos - f.begin() - 1];
            t = t + d[i];
            if (t < l || t > r)
                continue;
            ans = min(ans, max(t - l, r - t));
        }
        else if (pos == f.begin())
        {
            int t = f[pos - f.begin()];
            t = t + d[i];
            if (t < l || t > r)
                continue;
            ans = min(ans, max(t - l, r - t));
        }
        else
        {
            int t = f[pos - f.begin()];
            t = t + d[i];
            if (t >= l && t <= r)
                ans = min(ans, max(t - l, r - t));
            t = f[pos - f.begin() - 1];
            t = t + d[i];
            if (t < l || t > r)
                continue;
            ans = min(ans, max(t - l, r - t));
        }
    }
    if (n <= 2)
        cout << ans << endl;
    else
        cout << max(ans, num[n - 3].first) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
