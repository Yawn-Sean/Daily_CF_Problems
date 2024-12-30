// 0821
#include <bits/stdc++.h>
constexpr int MOD = 998244353;

std::vector<int> visited_x(2e5 + 1);
std::vector<int> visited_y(2e5 + 1);

void solve() {
    int n, m, k, q;
    std::cin >> n >> m >> k >> q;
    std::vector<int> xs(q);
    std::vector<int> ys(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> xs[i] >> ys[i];
        xs[i]--, ys[i]--;
    }

    int ret = 1;
    int row_occupied = 0;
    int col_occupied = 0;
    for (int i = q - 1; i >= 0; --i) {
        if ((!visited_x[xs[i]] && col_occupied < m) || (!visited_y[ys[i]] && row_occupied < n)) {
            ret = 1ll * ret * k % MOD;
            if (!visited_x[xs[i]]) {
                visited_x[xs[i]] = 1;
                ++row_occupied;
            }
            
            if (!visited_y[ys[i]]) {
                visited_y[ys[i]] = 1;
                ++col_occupied;
            }
        }
    }
    std::cout << ret << '\n';

    for (int i = 0; i < q; ++i) {
        visited_x[xs[i]] = 0;
        visited_y[ys[i]] = 0;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}