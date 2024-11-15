// 1114
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = s[j] - '0';
        }
    }

    int ret = n * m;
    std::vector<int> mid(m, 0);
    std::vector<int> right(m, 0);
    for (int up = 0; up <= n - 5; ++up) {
        std::fill(begin(mid), end(mid), 0);
        for (int k = 0; k < m; ++k) {
            for (int down = up + 1; down < up + 4; ++down) {
                mid[k] += grid[down][k];
            }
        }

        for (int down = up + 4; down < n; ++down) {
            for (int k = 0; k < m; ++k) {
                right[k] = mid[k];
            }

            for (int k = 1; k < m; ++k) {
                right[k] = 2 - grid[up][k] - grid[down][k];
            }

            for (int k = 1; k < m; ++k) {
                right[k] += right[k - 1];
            }

            int cur = m * n;
            for (int col = m - 1; col >= 3; --col) {
                cur = std::min(cur, right[col - 1] - mid[col] + down - up - 1);
                ret = std::min(ret, cur - right[col - 3] - mid[col - 3] + down - up - 1);   
            }

            for (int col = 0; col < m; ++col) {
                mid[col] += grid[down][col];
            }
        }
    }

    std::cout << ret << '\n';
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