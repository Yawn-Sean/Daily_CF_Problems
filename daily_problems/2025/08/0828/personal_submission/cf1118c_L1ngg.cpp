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
    std::vector<int> a(1001, 0);
    for (int i = 1;i <= n * n;i++) {
        int x;  std::cin >> x;
        a[x]++;
    }

    std::vector ans(n + 1, std::vector<int>(n + 1));
    int p = 1;
    for (int i = 1;i <= n / 2;i++)
        for (int j = 1;j <= n / 2;j++)
        {
            while (p <= 1000 && a[p] < 4) p++;
            if (p == 1001) {
                std::cout << "NO";
                return;
            }
            ans[i][j] = ans[n + 1 - i][j] = ans[i][n + 1 - j] = ans[n + 1 - i][n + 1 - j] = p;
            a[p] -= 4;
        }

    if (n & 1) {
        p = 1;
        for (int i = 1;i <= n / 2;i++)
        {
            while (p <= 1000 && a[p] < 2) p++;
            if (p == 1001) {
                std::cout << "NO";
                return;
            }
            ans[i][(n + 1) / 2] = ans[n + 1 - i][(n + 1) / 2] = p;
            a[p] -= 2;
            while (p <= 1000 && a[p] < 2) p++;
            if (p == 1001) {
                std::cout << "NO";
                return;
            }
            ans[(n + 1) / 2][i] = ans[(n + 1) / 2][n + 1 - i] = p;
            a[p] -= 2;
        }
        p = 1;
        while (p <= 1000 && a[p] < 1) p++;
        if (p == 1001) {
            std::cout << "NO";
            return;
        }
        ans[(n + 1) / 2][(n + 1) / 2] = p;
    }
    std::cout << "YES\n";
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            std::cout << ans[i][j] << " \n"[j == n];
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