// 1118
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    std::cin >> k;
    if (k == 0) {
        std::cout << "+\n";
        return 0;
    }

    vector<vector<int>> mat(1 << k, vector<int>(1 << k));
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;

    for (int i = 2; i <= k; ++i) {
        vector<vector<int>> copy(1 << k, vector<int>(1 << k));
        const int len = 1 << i;
        for (int row = 0; row < len; ++row) {
            int oldIdx = row / 2;
            if (!(row & 1)) {
                copy[row].insert(copy[row].begin(), mat[oldIdx].begin(), mat[oldIdx].end());
                copy[row].insert(copy[row].begin() + len / 2, mat[oldIdx].begin(), mat[oldIdx].end());
            } else {
                copy[row].insert(copy[row].begin(), mat[oldIdx].begin(), mat[oldIdx].end());
                for (int col = len / 2; col < len; ++col) {
                    copy[row][col] = 1 - mat[oldIdx][col - len / 2];
                }
            }
        }
        mat = std::move(copy);
    }

    for (int i = 0; i < (1 << k); ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            std::cout << (mat[i][j] == 1 ? '+' : '*');
        }
        std::cout << '\n';
    }

    return 0;
}