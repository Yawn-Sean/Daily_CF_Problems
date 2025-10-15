#include <bits/stdc++.h>

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (int i = 0;i < n;i++)
        std::cin >> a[i];

    int res = 0;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++) {
            int tmp = a[i][j];
            if (i + 1 < n) tmp -= a[i + 1][j];
            if (j + 1 < m) tmp -= a[i][j + 1];
            if (i + 1 < n && j + 1 < m) tmp += a[i + 1][j + 1];
            if (tmp) res++;
        }
    std::cout << res;
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