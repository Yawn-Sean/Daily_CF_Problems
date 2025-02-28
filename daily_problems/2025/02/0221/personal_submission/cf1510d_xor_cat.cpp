#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using real = long double;

constexpr real inf = 1E100;
constexpr real eps = 1E-6;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, d;
    std::cin >> n >> d;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::array<real, 10>> f(n + 1);
    std::vector<std::array<std::pair<int, int>, 10>> lst(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i][a[i] % 10] = std::log(a[i]);
        for (int j = 0; j <= 9; j++) {
            if (f[i - 1][j] && f[i - 1][j] + std::log(a[i]) - f[i][(j * a[i]) % 10] > eps) {
                f[i][(j * a[i]) % 10] = f[i - 1][j] + std::log(a[i]);
                lst[i][(j * a[i]) % 10] = {i - 1, j};
            }
            if (f[i - 1][j] && f[i - 1][j] - f[i][j] > eps) {
                f[i][j] = f[i - 1][j];
                lst[i][j] = {i - 1, j};
            }
        }
    }

    if (f[n][d] == 0) {
        std::cout << -1 << "\n";
        return 0;
    }

    std::vector<int> ans;
    auto now = std::make_pair(n, d);
    auto ed = std::make_pair(0, 0);
    while (now != ed) {
        auto [i, j] = now;
        auto nxt = lst[i][j];
        if (f[nxt.first][nxt.second] != f[i][j]) {
            ans.push_back(a[i]);
        }
        now = nxt;
    }

    std::ranges::sort(ans);

    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }

    return 0;
}
