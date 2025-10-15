#include <bits/stdc++.h>
using i64 = long long;
const i64 INF = 1e18;
void solve()
{
    int n;  i64 L;  std::cin >> n >> L;
    std::vector<i64> a(n + 1);
    a[0] = 0, a[n] = L;
    for (int i = 1;i <= n - 1;i++)  std::cin >> a[i];

    int p1 = 0, p2 = 0;
    i64 ans = INF;
    for (int i = 2;i <= n - 2;i++) {
        while (a[p1 + 1] <= a[i] - a[p1 + 1]) p1++;
        while (a[p2 + 1] - a[i] <= a[n] - a[p2 + 1]) p2++;

        for (int d1 = p1;d1 <= p1 + 1;d1++)
            for (int d2 = p2;d2 <= p2 + 1;d2++)
            {
                i64 mx = std::max({ a[n] - a[d2] ,a[d2] - a[i],a[i] - a[d1] ,a[d1] });
                i64 mn = std::min({ a[n] - a[d2] ,a[d2] - a[i],a[i] - a[d1] ,a[d1] });
                ans = std::min(ans, mx - mn);
            }
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}
