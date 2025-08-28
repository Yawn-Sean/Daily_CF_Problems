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
    int n;  std::cin >> n;
    std::vector<int> a(n);
    for (int i = 1;i <= n - 1;i++)   std::cin >> a[i];

    std::vector<i64> left0(n + 1), left1(n + 1);
    std::vector<i64> right0(n + 1), right1(n + 1);
    for (int i = 1;i <= n - 1;i++)
    {
        if (a[i] > 1) left1[i + 1] = left1[i] + a[i] / 2 * 2;
        left0[i + 1] = std::max(left0[i] + a[i] - !(a[i] & 1), left1[i] + a[i]);
    }
    for (int i = n - 1;i >= 1;i--)
    {
        if (a[i] > 1) right1[i] = right1[i + 1] + a[i] / 2 * 2;
        right0[i] = std::max(right0[i + 1] + a[i] - !(a[i] & 1), right1[i + 1] + a[i]);
    }
    i64 mx = 0;
    for (int i = 1;i <= n;i++)
    {
        mx = std::max(mx, left0[i] + right1[i]);
        mx = std::max(mx, right0[i] + left1[i]);
    }
    std::cout << mx;
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