#include <bits/stdc++.h>
void solve()
{
    int n;  std::cin >> n;
    std::map<int, int> m;

    for (int i = 0;i < 10;i++) {
        std::vector<int> ask;
        for (int j = 1;j <= n;j++)
            if ((j >> i) & 1) ask.push_back(j);

        if (ask.size() == 0) break;
        std::cout << ask.size() << " ";
        for (auto& x : ask)    std::cout << x << " ";
        std::cout << std::endl;

        std::vector<int> res(ask.size());
        for (auto& x : res) {
            std::cin >> x;
            m[x] |= (1 << i);
        }
    }

    std::vector<int> ans(n + 1);
    for (auto [x, y] : m)
        ans[y] = x;
    std::cout << "! ";
    for (int i = 1;i <= n;i++)  std::cout << ans[i] << " ";
    std::cout << std::endl;
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