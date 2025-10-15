#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e6;

void solve()
{
    int n;  std::cin >> n;
    std::vector<int> x(n + 1), y(n + 1), v(n + 1);
    for (int i = 1;i <= n;i++)   std::cin >> x[i] >> y[i] >> v[i];

    i64 ans = 0;
    auto cal = [&]() {
        i64 res = 0;
        std::vector<int> cnt(N + 1), order(N + 1);

        for (int i = 1;i <= n;i++)
            cnt[x[i]] += v[i];

        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&](int i, int j) {
            return cnt[i] > cnt[j];
            });

        res = cnt[order[0]] + cnt[order[1]] + cnt[order[2]];

        std::map<int, std::vector<int>> mp;
        for (int i = 1;i <= n;i++)
            mp[y[i]].push_back(i);

        for (auto& [val, vec] : mp) {
            i64 now = 0;

            for (auto idx : vec)
            {
                now += v[idx];
                cnt[x[idx]] -= v[idx];
            }

            i64 first = 0, second = 0;
            for (int i = 0;i < vec.size() + 2;i++)
            {
                if (cnt[order[i]] >= first) second = first, first = cnt[order[i]];
                else if (cnt[order[i]] >= second) second = cnt[order[i]];
            }
            res = std::max(res, now + first + second);

            for (auto idx : vec) {
                cnt[x[idx]] += v[idx];
            }
        }
        return res;
        };

    ans = cal();
    for (int i = 1;i <= n;i++) std::swap(x[i], y[i]);

    ans = std::max(ans, cal());
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
