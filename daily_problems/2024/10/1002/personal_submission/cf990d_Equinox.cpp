#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    if (a > 1 && b > 1) {
        std::cout << "NO\n";
        return;
    }

    std::vector<std::vector<int>> g(n, std::vector<int>(n));

    if (a > 1) {
        for (int i = 0; n - a >= i; ++ i)
            for (int j = 0; n - a >= j; ++ j)
                if (i != j)
                    g[i][j] = 1;

    } else if(a == 1) {
        if (b > 1) {
            for (int i = 0; i < n; ++ i)
                for (int j = 0; j < n; ++ j)
                    if (i != j)
                        g[i][j] = 1;
            for (int i = 0; n - b >= i; ++ i)
                for (int j = 0; n - b >= j; ++ j)
                    if (i != j)
                        g[i][j] = 0;
        } else {
            if (n == 2 || n == 3) {
                std::cout << "NO\n";
                return;
            }
            for (int i = 0; i < n; ++ i)
                for (int j = 0; j < n; ++ j)
                    if (abs(i - j) == 1)
                        g[i][j] = 1;
        }
    }

    std::cout << "YES\n";

    for (int i = 0; i < n; ++ i, std::cout << '\n') 
        for (int j = 0; j < n; ++ j)
            std::cout << g[i][j];
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