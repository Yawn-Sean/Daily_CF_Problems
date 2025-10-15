#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a2 = std::array<int, 2>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;   std::cin >> n >> m;
    std::vector<a2> a(m + 1);
    int sum = 0;
    for (int i = 1;i <= m;i++) {
        std::cin >> a[i][0];
        a[i][0] = std::min(n / 2, a[i][0]);
        a[i][1] = i;
        sum += a[i][0];
    }

    if (sum < n) {
        std::cout << -1;
        return;
    }

    int i = m;
    std::sort(a.begin() + 1, a.end());
    std::vector<int> ans(n + 1);
    for (int t = 1;t <= n;t += 2) {
        ans[t] = a[i][1], a[i][0]--;
        if (!a[i][0]) i = i % m + 1;
    }
    for (int t = 2;t <= n;t += 2) {
        ans[t] = a[i][1], a[i][0]--;
        if (!a[i][0]) i = i % m + 1;
    }
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