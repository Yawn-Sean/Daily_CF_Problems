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
const int mod = 998244353;

i64 qpow(i64 x, i64 b) {
    i64 ret = 1;
    while (b) {
        if (b & 1) ret = ret * x % mod;
        b >>= 1;
        x = x * x % mod;
    }
    return ret;
}

void solve()
{
    int n, q;   std::cin >> n >> q;
    std::string s;  std::cin >> s;
    s = " " + s;
    i64 c1 = 0, c0 = 0;
    i64 inv4 = qpow(4, mod - 2);
    for (int i = 1;i <= n;i++) {
        if (s[i] == '1') c1++;
        else c0++;
    }
    while (q--) {
        int p;  std::cin >> p;
        if (s[p] == '1')
        {
            c1--, c0++;
            s[p] = '0';
        }
        else {
            c0--, c1++;
            s[p] = '1';
        }
        std::cout << ((1ll * c0 * (c0 + 1) / 2 % mod + 1ll * c1 * (c1 + 1) / 2 % mod - 1ll * c0 * c1 % mod - 1) % mod + mod) % mod * qpow(2, n - 1) % mod * inv4 % mod << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
        // std::cout << '\n';
    }
}