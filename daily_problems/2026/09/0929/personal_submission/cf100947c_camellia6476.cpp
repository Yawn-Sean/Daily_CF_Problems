#include <iostream>
#include <algorithm>
using namespace std;
using i64 = long long;

constexpr int N = 10010;
int T, n;
i64 a[N], pre1[N], pre2[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i & 1)
        {
            if (i == 1)
                pre1[i] = a[i];
            else
                pre1[i] = pre1[i - 2] + a[i];
        }
        else
        {
            if (i == 2)
                pre2[i] = a[i];
            else
                pre2[i] = pre2[i - 2] + a[i];
        }
    }
    if (n & 1)
    {
        i64 ans = -1e18;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                ans = max(ans, pre2[i - 1] + pre1[n] - pre1[max(i - 2, 0)]);
            else
                ans = max(ans, pre1[i - 1] + pre2[n - 1] - pre2[i - 2]);
        }
        cout << ans << '\n';
    }
    else
        cout << max(pre2[n], pre1[n - 1]) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
        solve();
    return 0;
}