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
    只关注后三位
    先算后三位初始tot
    如果全都下取整那么差就是tot
    然后考虑枚举上取整的数目，维护绝对值最小值
*/

void solve()
{
    int n;
    std::cin >> n;
    int tot = 0, c0 = 0;
    for (int i = 0; i < n * 2; ++ i) {
        std::string s;
        std::cin >> s;
        int a = 0;
        for (int i = s.size() - 3; i < s.size(); ++ i)
            a = a * 10 + (s[i] ^ 48);
        tot += a;
        if (!a) 
            ++ c0;
    }
    int res = 1000 * 2 * n;
    for (int i = std::max(n - c0, 0); i <= std::min(n, 2 * n - c0); ++ i)
        res = std::min(res, abs(tot - i * 1000));
    
    std::cout << res / 1000 << '.';
    res %= 1000;
    std::cout << res / 100;
    res %= 100;
    std::cout << res / 10 << res % 10;
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