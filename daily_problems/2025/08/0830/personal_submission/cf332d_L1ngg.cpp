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
    int n, k;
    std::cin >> n >> k;
    std::vector g(n, std::vector<i64>(n, -1));
    for (int i = 0;i < n;i++)
        for (int j = i + 1;j < n;j++)
        {
            std::cin >> g[i][j];
            g[j][i] = g[i][j];
        }

    if (k == 2) {
        i64 ans = 0;
        for (int i = 0;i < n;i++) {
            i64 cnt = 0, sum = 0;
            for (int j = 0;j < n;j++)
                if (g[i][j] != -1) {
                    cnt++;
                    sum += g[i][j];
                }
            ans += (cnt - 1) * sum;
        }
        std::cout << ans / (1ll * n * (n - 1) / 2);
    }
    else {
        i64 ans = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (g[i][j] != -1) ans += g[i][j];
        std::cout << ans / n;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
}