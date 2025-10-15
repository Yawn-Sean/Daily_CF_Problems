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
    i64 a, b;   int k;
    std::cin >> a >> b >> k;
    i64 block = 1;
    for (int i = 2;i <= k;i++)
        block = std::lcm(i, block);

    // std::cout << block;
    i64 ans = 0;
    if (a / block != b / block) {
        std::vector<int> f(block + 1, inf);
        f[0] = 0;
        for (int i = 1;i <= block;i++)
        {
            f[i] = f[i - 1] + 1;
            for (int j = 2;j <= k;j++)
                f[i] = std::min(f[i], f[i - i % j] + 1);
        }
        ans += f[a % block];
        a -= a % block;
        i64 cnt = (a - b) / block;
        ans += cnt * f[block];
        a -= cnt * block;
        a--, ans++;
    }

    a %= block;
    b %= block;
    std::vector<int> f(a + 1, inf);
    f[b] = 0;
    for (int i = b + 1;i <= a;i++)
    {
        f[i] = f[i - 1] + 1;
        for (int j = 2;j <= k;j++)
            f[i] = std::min(f[i], f[i - i % j] + 1);
    }
    ans += f[a];
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