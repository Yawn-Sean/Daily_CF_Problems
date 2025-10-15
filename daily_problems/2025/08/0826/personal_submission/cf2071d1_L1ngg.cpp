#include <bits/stdc++.h>
using i64 = long long;
void solve()
{
    i64 n, l, r;    std::cin >> n >> l >> r;
    std::vector<int> a(n);
    for (int i = 0;i < n;i++)    std::cin >> a[i];

    if (n % 2 == 0) {
        int v = 0;
        for (int i = 0;i < n / 2;i++)
            v ^= a[i];
        a.push_back(v);
        n++;
    }

    int res = 0;
    for (auto x : a) res ^= x;

    auto cal = [&](auto&& self, i64 x) -> int {
        if (x <= n) return a[x - 1];
        if (x <= 2 * n)
        {
            int v = 0;
            for (int i = 0;i < x / 2;i++)
                v ^= a[i];
            return v;
        }

        i64 v = x / 2;
        if (v % 2 == 0) return  res ^ self(self, v);
        else return res;
        };

    std::cout << cal(cal, l);
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