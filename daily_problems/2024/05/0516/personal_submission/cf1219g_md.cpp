// 0516
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    vector<vector<i64>> grid(n, vector<i64>(m));
    vector<i64> row_sum(n), col_sum(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
        }
    }

    if (min(n, m) <= 4) {
        cout << accumulate(begin(row_sum), end(row_sum), 0ll) << endl;
        return 0;
    }
    
    auto get_max4 = [&](const vector<i64>& nums, int cnt) -> i64 {
        array<i64, 4> max4 = {0ll};
        fill(begin(max4), end(max4), 0ll);
        for (int i = 0; i < ssize(nums); ++i) {
            if (nums[i] >= max4[0]) {
                max4[3] = max4[2];
                max4[2] = max4[1];
                max4[1] = max4[0];
                max4[0] = nums[i];
            } else if (nums[i] >= max4[1]) {
                max4[3] = max4[2];
                max4[2] = max4[1];
                max4[1] = nums[i];
            } else if (nums[i] >= max4[2]) {
                max4[3] = max4[2];
                max4[2] = nums[i];
            } else if (nums[i] > max4[3]) {
                max4[3] = nums[i];
            }
        }
        return accumulate(begin(max4), begin(max4) + cnt, 0ll);
    }; 

    // 4 rows
    i64 ret = get_max4(row_sum, 4);
    
    // 4 cols;
    ret = max(ret, get_max4(col_sum, 4));

    // 2 rows + 2 cols
    if (n < m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                auto col_sum_copy = col_sum;
                for (int col_id = 0; col_id < m; ++col_id) {
                    col_sum_copy[col_id] -= grid[i][col_id] + grid[j][col_id];
                }
                ret = max(ret, get_max4(col_sum_copy, 2) + row_sum[i] + row_sum[j]);
            }
        }
    } else {        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                auto row_sum_copy = row_sum;
                for (int row_id = 0; row_id < n; ++row_id) {
                    row_sum_copy[row_id] -= grid[row_id][i] + grid[row_id][j];
                }
                ret = max(ret, get_max4(row_sum_copy, 2) + col_sum[i] + col_sum[j]);
            }
        }
    }
        
    // 1 row + 3 cols
    for (int row_id = 0; row_id < n; ++row_id) {
        auto col_sum_copy = col_sum;
        for (int i = 0; i < m; ++i) {
            col_sum_copy[i] -= grid[row_id][i];
        }
        ret = max(ret, row_sum[row_id] + get_max4(col_sum_copy, 3));
    }

    // 1 col + 3 rows
    for (int col_id = 0; col_id < m; ++col_id) {
        auto row_sum_copy = row_sum;
        for (int i = 0; i < n; ++i) {
            row_sum_copy[i] -= grid[i][col_id];
        }
        ret = max(ret, col_sum[col_id] + get_max4(row_sum_copy, 3));
    }

    cout << ret << endl;

    return 0;
}