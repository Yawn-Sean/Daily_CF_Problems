#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 inf = 1e12;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k, q;
    std::cin >> n >> m >> k >> q;
    vector<vector<i64>> bounds(2, vector<i64>(n, inf));
    bounds[1].assign(n, -inf);
    while (k--) {
        i64 x, y; cin >> x >> y;
        --x; --y;
        bounds[0][x] = min(bounds[0][x], y);
        bounds[1][x] = max(bounds[1][x], y);
    }

    vector<i64> safe_cols(q);
    copy_n(istream_iterator<i64>(cin), q, begin(safe_cols));
    transform(begin(safe_cols), end(safe_cols), begin(safe_cols), [](i64 x) { return x - 1; });
    sort(begin(safe_cols), end(safe_cols));

    const auto idx_list = initializer_list<int>{0, 1};
    vector<vector<i64>> dp(2, vector<i64>(n, inf));
    vector<int> last_pos(2, 0);
    if (bounds[0][0] != inf) {
        dp[0][0] = 2 * bounds[1][0] - bounds[0][0];
        dp[1][0] = bounds[1][0];
        for (auto idx : idx_list) {
            last_pos[idx] = bounds[idx][0];
        }
    } else {
        dp[0][0] = dp[1][0] = 0;
    }

    int move_up_cost = 1;
    for (int i = 1; i < n; ++i) {
        if (bounds[0][i] == inf) {
            for (auto idx : idx_list) {
                // N.B.: Don't add move_up_cost to dp[idx][i] here because there could be NO more treasures left
                dp[idx][i] = dp[idx][i - 1];
            }
            move_up_cost++;
            continue;
        }

        const auto bound_width = bounds[1][i] - bounds[0][i];    
        for (auto last_pos_idx : idx_list) {
            auto idx = lower_bound(begin(safe_cols), end(safe_cols), last_pos[last_pos_idx]) - begin(safe_cols);
            for (int safe_col_idx = idx - 1; safe_col_idx <= idx; ++safe_col_idx) {
                if (safe_col_idx < 0 || safe_col_idx >= q) continue;
                for (auto cur_pos_idx : idx_list) {
                    const auto cur_traverse_cost = abs(safe_cols[safe_col_idx] - bounds[cur_pos_idx ^ 1][i]) + bound_width;
                    const auto cur_cost_l = dp[last_pos_idx][i - 1] + abs(safe_cols[safe_col_idx] - last_pos[last_pos_idx]) + cur_traverse_cost;
                    const auto cur_cost_r = dp[last_pos_idx ^ 1][i - 1] + abs(safe_cols[safe_col_idx] - last_pos[last_pos_idx ^ 1]) + cur_traverse_cost;
                    dp[cur_pos_idx][i] = min({dp[cur_pos_idx][i], cur_cost_l, cur_cost_r});
                }
            }
        }

        for (auto idx : idx_list) {
            dp[idx][i] += move_up_cost;
            last_pos[idx] = bounds[idx][i];
        }
        move_up_cost = 1;
    }

    cout << min(dp[0][n-1], dp[1][n-1]) << endl;
    return 0;
}