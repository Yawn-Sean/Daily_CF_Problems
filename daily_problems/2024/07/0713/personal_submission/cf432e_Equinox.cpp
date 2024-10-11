#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n, std::vector<int>(m));
    
    std::array<int, 5> dir { 1, 0, -1, 0, 1 };

    auto check = [&](int i, int j) -> int {
        if (g[i][j]) return g[i][j];
        for (int c = 1; c <= 26; ++ c) {
            bool f = true;
            for (int k = 0; k < 4; ++ k) {
                int ii = i + dir[k], jj = j + dir[k + 1];
                if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                if (g[ii][jj] == c) f = false;
            }
            if (f) return c;
        }

        return 0;
    };

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            if (g[i][j]) continue;
            int c = check(i, j);
            int sz = 0;
            while (j + sz < m && i + sz < n && check(i, j + sz) == c) 
                ++ sz;
            -- sz;
            for (int ii = i; ii <= i + sz; ++ ii)
                for (int jj = j; jj <= j + sz; ++ jj)
                    g[ii][jj] = c;
        }
    }

    for (int i = 0; i < n; ++ i, std::cout << '\n') 
        for (int j = 0; j < m; ++ j)
            std::cout << char(g[i][j] - 1 + 'A');
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}