#include <bits/stdc++.h>
#define sc scanf
using i64 = long long;
using PII = std::pair<int, int>;
constexpr int inf32 = 1e9 + 7;
constexpr i64 inf64 = 1e18 + 7;
constexpr int P = 998244353;
constexpr double eps = 1e-6;

// #define DEBUG

/*
    L: -lb
    R: +lb

    U: -lb, | lb * 2
*/

void solve()
{
    i64 n, q;
    std::cin >> n >> q;

    i64 u;
    std::string s;
    for (int i = 0; i < q; ++ i) {
        std::cin >> u >> s;

        for (char ch : s) {
            i64 lb = u & -u;

            if (ch == 'L') {
                u -= lb / 2;
            }
            else if(ch == 'R') {
                u += lb / 2;
            }
            else {
                if (lb * 2 < n)
                    u -= lb, u |= lb * 2;
            }
        }
        std::cout << u << '\n';
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_--)
        solve();
    return 0;
}