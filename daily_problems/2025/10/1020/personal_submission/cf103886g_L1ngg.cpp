#include <bits/stdc++.h>
void solve()
{
    int n;  std::cin >> n;
    auto cal = [&](auto&& self, int x) -> std::vector<int> {
        if (x == 1) return { 1 };
        std::vector<int> ans;
        for (auto num : self(self, x / 2)) ans.push_back(num * 2);
        for (auto num : self(self, x - x / 2)) ans.push_back(num * 2 - 1);
        return ans;
        };
    for (auto x : cal(cal, n)) std::cout << x << " ";
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