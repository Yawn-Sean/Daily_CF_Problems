#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector g(n, std::vector<int>(m));

    if (std::min(n, m) > 1 && n * m - 1 == k) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";

    if (k == 1) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                std::cout << 0;
            }
            std::cout << "\n";
        }
        return;
    }

    if (k <= m) {
        for (int y = 0; y < m; y++) {
            if (y + 1 <= k) {
                g[0][y] = y % 2;
            } else {
                g[0][y] = g[0][y - 1];
            }
        }
        for (int x = 1; x < n; x++) {
            for (int y = 0; y < m; y++) {
                g[x][y] = g[x - 1][y];
            }
        }
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                std::cout << g[x][y];
            }
            std::cout << "\n";
        }
        return;
    }


    int r = (k + m - 1) / m;
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < m; y++) {
            g[x][y] = (x + y) % 2;
        }
    }

    int d = r * m - k;
    if (d == 1) {
        for (int x = r; x < n; x++) {
            for (int y = 0; y < m; y++) {
                g[x][y] = g[x - 1][y];
            }
        }
        g[r - 1][m - 1] = !g[r - 1][m - 1];
    } else if (d > 1) {
        d--;
        for (int i = 0; i < d; i++) {
            g[r - 1][m - 1 - i] = !g[r - 1][m - 1 - i];
        }
        for (int x = r; x < n; x++) {
            for (int y = 0; y < m; y++) {
                g[x][y] = g[x - 1][y];
            }
        }
    } else {
        for (int x = r; x < n; x++) {
            for (int y = 0; y < m; y++) {
                g[x][y] = g[x - 1][y];
            }
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            std::cout << g[x][y];
        }
        std::cout << "\n";
    }


}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
