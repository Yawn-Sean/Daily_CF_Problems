#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;
constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        copy_n(istream_iterator<int>(std::cin), m, begin(mat[i]));
    }

    vector<vector<int>> costs(n, vector<int>(n, inf));
    vector<vector<int>> last_cost(n, vector<int>(n, inf));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                costs[i][j] = min(costs[i][j], abs(mat[i][k] - mat[j][k]));
            }
            for (int k = 0; k < m - 1; ++k) {
                last_cost[i][j] = min(last_cost[i][j], abs(mat[i][k + 1] - mat[j][k]));
            }
        }
    }

    int ret = 0;
    for (auto i = 0; i < n; ++i) {
        vector<vector<int>> dp(1 << n, vector<int>(n));
        dp[1 << i][i] = inf;
        for (auto mask = 0; mask < (1 << n); ++mask) {
            for (auto j = 0; j < n; ++j) {
                if ((mask >> j) & 1) {
                    for (int k = 0; k < n; ++k) {
                        if ((mask >> k) & 1) {
                            continue;
                        }
                        dp[mask | (1 << k)][k] = max(dp[mask | (1 << k)][k], min(dp[mask][j], costs[j][k]));
                    }
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            ret = max(ret, min(dp[(1 << n) - 1][j], last_cost[i][j]));
        }
    }

    cout << ret << endl;
    return 0;
}