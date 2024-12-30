#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e2 + 10, inf = 1e9, mod = 1e9 + 7;
double grid[MAXN][MAXN];
int n;
using pt = std::pair<int, int>;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.precision(15);
    std::cin >> n;
    int m = 1 << n;
    std::vector<std::vector<double>> grid(m, std::vector<double>(m));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> grid[i][j];
    std::vector<double> p(m, 1), dp(m, 0);
    for (int i = 0; i < n; ++i)
    {
        std::vector<double> ndp(m, 0), np(m, 0);
        for (int base = 0; base < m; base += (1 << i + 1))
        {
            for (int j = base; j < base + (1 << i); j++)
            {
                for (int k = base + (1 << i); k < base + (1 << i + 1); ++k)
                {
                    np[j] += p[j] * p[k] * grid[j][k] / 100;
                    np[k] += p[j] * p[k] * grid[k][j] / 100;
                    ndp[j] = std::max(ndp[j], dp[k]);
                    ndp[k] = std::max(ndp[k], dp[j]);
                }
            }
        }
        for (int t = 0; t < m; ++t)
            ndp[t] += np[t] * (1 << i) + dp[t];
        dp = ndp;
        p = np;
    }
    std::cout << *std::max_element(dp.begin(), dp.end());
    return 0;
}