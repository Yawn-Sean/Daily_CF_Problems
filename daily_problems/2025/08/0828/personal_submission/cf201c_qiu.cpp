#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
typedef pair<int, int> PII;
const int N = 300005, mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i < n; i++)
        cin >> a[i];
    vector<vector<int>> le(n + 2, vector<int>(2, 0)), re(n + 2, vector<int>(2, 0)); // 0来回，1最远
    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] > 1)
        {
            le[i][0] = a[i - 1] / 2 * 2 + le[i - 1][0];
            le[i][1] = ((a[i - 1] % 2 == 0) ? a[i - 1] - 1 : a[i - 1]) + max(le[i - 1][1], le[i - 1][0]);
        }
        else
        {
            le[i][1] = a[i - 1] + max(le[i - 1][1], le[i - 1][0]);
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] > 1)
        {
            re[i][0] = a[i] / 2 * 2 + re[i + 1][0];
            re[i][1] = ((a[i] % 2 == 0) ? a[i] - 1 : a[i]) + max(re[i + 1][1], re[i + 1][0]);
        }
        else
        {
            re[i][1] = a[i] + max(re[i + 1][1], re[i + 1][0]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int num1 = le[i][0] + re[i][0];
        int num2 = le[i][1] + re[i][0];
        int num3 = le[i][0] + re[i][1];
        // cout << i << ' ' << num1 << ' ' << num3 << ' ' << num2 << endl;
        ans = max(ans, max(num1, max(num2, num3)));
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;

    // cin >> T;
    while (T--)
        solve();
    return 0;
}
