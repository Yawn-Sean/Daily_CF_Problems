// 1111
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, m;
    std::cin >> n >> m;
    vector<int> aInRows(n, 0);
    vector<int> aInCols(m, 0);
    vector<string> grid(n);
    bool noA = true;
    bool allA = true;
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                noA = false;
                aInRows[i]++;
                aInCols[j]++;
            } else {
                allA = false;
            }
        }
    }

    int maxAInRow = *std::max_element(aInRows.begin(), aInRows.end());
    int maxAInCol = *std::max_element(aInCols.begin(), aInCols.end());

    if (allA) {
        std::cout << "0\n";
    } else if (noA) {
        std::cout << "MORTAL\n";
    } else if (aInRows[0] == m || aInRows[n - 1] == m || aInCols[0] == n || aInCols[m - 1] == n) {
        std::cout << "1\n";
    } else if (maxAInRow == m || maxAInCol == n || grid[0][0] == 'A' || grid[0][m - 1] == 'A' || grid[n - 1][m - 1] == 'A' || grid[n - 1][0] == 'A') {
        std::cout << "2\n";
    } else if (aInRows[0] || aInRows[n - 1] || aInCols[0] || aInCols[m - 1]) {
        std::cout << "3\n";
    } else {
        std::cout << "4\n";
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