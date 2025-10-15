#include <bits/stdc++.h>
using pii = std::pair<int, int>;

void solve()
{
    int n;  std::cin >> n;
    int a, b;   std::cin >> a >> b;
    std::vector<pii> num(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> num[i].first, num[i].second = i;

    if (a == b) {
        while (a--) std::cout << "1 ";
        while (b--)  std::cout << "2 ";
        return;
    }

    std::vector<int> ans(n + 1, 2);
    if (a > b) {
        std::sort(num.begin() + 1, num.end(), [&](pii& p1, pii& p2) {
            if (p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
            });
    }
    else std::sort(num.begin() + 1, num.end(), [&](pii& p1, pii& p2) {
        if (p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
        });

    for (int i = 1;i <= a;i++) ans[num[i].second] = 1;
    for (int i = 1;i <= n;i++)   std::cout << ans[i] << " ";
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