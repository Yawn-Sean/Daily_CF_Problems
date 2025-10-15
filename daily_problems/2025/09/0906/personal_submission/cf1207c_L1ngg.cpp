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
    i64 n, a, b;
    std::string s;
    std::cin >> n >> a >> b >> s;
    i64 f0 = b, f1 = INF;
    for (auto& x : s) {
        if (x == '1') f0 = INF, f1 = f1 + a + 2 * b;
        else {
            i64 nf0 = std::min(f0 + a + b, f1 + 2 * a + b);
            i64 nf1 = std::min(f0 + 2 * a + 2 * b, f1 + a + 2 * b);
            f0 = nf0;
            f1 = nf1;
        }
    }
    std::cout << f0;
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
