#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int m;
    std::cin >> m;

    std::vector<int> f(n + 1), g(n + 1), acc(n + 1);
    std::vector<std::array<int, 2>> pre(n + 1);
    for (int i = 0, last = 0; i < n; ++ i) {
        if (s[i] != 'b') pre[i + 1][1] = pre[i][0] + 1;
        if (s[i] != 'a') pre[i + 1][0] = pre[i][1] + 1;
        acc[i + 1] = acc[i] + (s[i] == '?');
    }

    for (int i = m - 1; i < n; ++ i) {
        if (pre[i + 1][m & 1] < m) {
            f[i + 1] = f[i], g[i + 1] = g[i];
        } else if (f[i] > f[i - m + 1] + 1) {
            f[i + 1] = f[i];
            g[i + 1] = g[i];
        } else if (f[i] < f[i - m + 1] + 1) {
            f[i + 1] = f[i - m + 1] + 1;
            g[i + 1] = g[i - m + 1] + acc[i + 1] - acc[i - m + 1];
        } else {
            f[i + 1] = f[i];
            g[i + 1] = std::min(g[i], g[i - m + 1] + acc[i + 1] - acc[i - m + 1]);
        }
    }

    std::cout << g[n] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef DEBUG
    int cur = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}