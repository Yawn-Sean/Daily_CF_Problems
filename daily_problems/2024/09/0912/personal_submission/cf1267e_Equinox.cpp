#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353;
constexpr int inf32 = 1E9 + 7;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> w(m, std::vector<int>(n));
    std::vector<int> sum(n);

    for (int i = 0; i < m; ++ i)
        for (int j = 0; j < n; ++ j)
            std::cin >> w[i][j], sum[j] += w[i][j];

    int ans = m;
    std::vector<int> path(m);
    std::iota(path.begin(), path.end(), 1);

    for (int i = 0; i + 1 < n; ++ i) {
        int res = sum[i] - sum[n - 1], cnt = 0;
        std::vector<std::pair<int, int>> buf;
        for (int j = 0; j < m; ++ j) {
            if (w[j][n - 1] > w[j][i])
                buf.emplace_back(w[j][n - 1] - w[j][i], j);
        }
        
        std::ranges::sort(buf, std::greater<std::pair<int, int>>());
        for (auto &[x, i] : buf) {
            if (res >= 0) break;
            res += x;
            ++ cnt;
        }
        if (cnt < ans) {
            ans = std::min(ans, cnt);
            path.clear();
            for (auto &[x, i] : buf) {
                path.push_back(i + 1);
                if (path.size() == cnt) break;
            }
        }
    }

    std::cout << ans << '\n';
    for (int x : path)
        std::cout << x << ' ';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}