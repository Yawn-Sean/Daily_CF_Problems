#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n, std::vector<int>(m));

    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j)
            std::cin >> g[i][j];

    std::vector<std::vector<int>> f0(n, std::vector<int>(m)), f1(n, std::vector<int>(m)), f2(n, std::vector<int>(m)), f3(n, std::vector<int>(m));

    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j) {
            int v = 0;
            if (i) v = std::max(v, f0[i - 1][j]);
            if (j) v = std::max(v, f0[i][j - 1]);
            f0[i][j] = v + g[i][j];
        }

    for (int i = n - 1; ~i; -- i)
        for (int j = m - 1; ~j; -- j) {
            int v = 0;
            if (i + 1 < n) v = std::max(v, f1[i + 1][j]);
            if (j + 1 < m) v = std::max(v, f1[i][j + 1]);
            f1[i][j] = v + g[i][j];
        }

    for (int i = 0; i < n; ++ i)
        for (int j = m - 1; ~j; -- j) {
            int v = 0;
            if (i) v = std::max(v, f2[i - 1][j]);
            if (j + 1 < m) v = std::max(v, f2[i][j + 1]);
            f2[i][j] = v + g[i][j];
        }

    for (int i = n - 1; ~i; -- i)
        for (int j = 0; j < m; ++ j) {
            int v = 0;
            if (i + 1 < n) v = std::max(v, f3[i + 1][j]);
            if (j) v = std::max(v, f3[i][j - 1]);
            f3[i][j] = v + g[i][j];
        }

    int res = 0;

    for (int i = 1; i + 1 < n; ++ i)
        for (int j = 1; j + 1 < m; ++ j) {
            res = std::max(res, f0[i - 1][j] + f1[i + 1][j] + f2[i][j + 1] + f3[i][j - 1]);
            res = std::max(res, f0[i][j - 1] + f1[i][j + 1] + f2[i - 1][j] + f3[i + 1][j]);
        }

    std::cout << res;
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