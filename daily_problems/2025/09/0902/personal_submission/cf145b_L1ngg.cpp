#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int a, b, x, y; std::cin >> a >> b >> x >> y;
    if (std::abs(x - y) >= 2) {
        std::cout << -1;
        return;
    }
    std::vector<int> ans;
    if (x > y || (x == y && a >= x + 1)) {
        for (int i = 1;i <= x;i++)
        {
            ans.push_back(4);
            ans.push_back(7);
        }
        a -= x, b -= x;
        if (x == y) ans.push_back(4), a--;
    }
    else {
        for (int i = 1;i <= y;i++)
        {
            ans.push_back(7);
            ans.push_back(4);
        }
        a -= y, b -= y;
        if (x == y) ans.push_back(7), b--;
    }
    if (a >= 0 && b >= 0) {
        std::vector<int> res;
        for (auto& x : ans) {
            if (x == 4)
                while (a) res.push_back(4), a--;
            res.push_back(x);
        }

        if (res.back() == 7)
            while (b)  res.push_back(7), b--;

        else {
            res.pop_back();
            while (b)  res.push_back(7), b--;
            res.push_back(4);
        }

        for (auto& x : res) std::cout << x;
    }
    else std::cout << -1;
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