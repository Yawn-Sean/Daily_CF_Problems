#include <bits/stdc++.h>
void solve()
{
    int n, c;   std::cin >> n >> c;
    std::vector a(n + 1, std::vector<int>());
    for (int i = 1;i <= n;i++) {
        int x;  std::cin >> x;
        a[i].resize(x + 1);
        a[i][0] = x;
        for (int j = 1;j <= x;j++)   std::cin >> a[i][j];
    }

    std::vector<int> d(c + 2);
    for (int i = 1;i <= n - 1;i++) {
        int len1 = a[i][0], len2 = a[i + 1][0];
        int p1 = 1, p2 = 1;
        while (p1 <= len1 && p2 <= len2) {
            if (a[i][p1] != a[i + 1][p2]) break;
            p1++, p2++;
        }
        if (p1 == len1 + 1) { d[0]++; continue; }
        if (p2 == len2 + 1) {
            std::cout << -1;
            return;
        }
        if (a[i][p1] > a[i + 1][p2]) {
            d[c - a[i][p1] + 1]++;
            d[c - a[i + 1][p2] + 1]--;
        }
        else {
            d[0]++;
            d[c - a[i + 1][p2] + 1]--;
            d[c - a[i][p1] + 1]++;
        }
    }
    for (int i = 1;i <= c;i++) d[i] += d[i - 1];
    for (int i = 0;i <= c;i++) {
        if (d[i] == n - 1) {
            std::cout << i;
            return;
        }
    }
    std::cout << -1;
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