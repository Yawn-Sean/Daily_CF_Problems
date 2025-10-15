#include <bits/stdc++.h>

void solve()
{
    int n, m;   std::cin >> n >> m;
    if (n == m && n == 1) {
        std::cout << 1;
        return;
    }
    if (n * 2 > m) {
        std::cout << 0;
        return;
    }
    std::cout << (Z)m * comb.C(m - n - 1, n - 1) * comb.fac(n - 1);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}