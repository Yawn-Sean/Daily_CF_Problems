// 1107
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;
std::vector<char> idxToChar;

void solve() {
    int r, c, k;
    std::cin >> r >> c >> k;
    std::vector<std::string> grid(r);

    int countR = 0;
    for (int i = 0; i < r; ++i) {
        std::cin >> grid[i];
        countR += std::count(grid[i].begin(), grid[i].end(), 'R');
    }

    int avg = countR / k;
    int rem = countR % k;

    std::vector<int> assign(k, avg);
    for (int i = 0; i < rem; ++i) {
        ++assign[i];
    }
    std::vector<std::vector<int>> ret(r, std::vector<int>(c, -1));

    int x = 0;
    int y = 0;
    int dx = 1;
    for (int i = 0; i < k; ++i) {
        auto visitedAndAssign = [&]() {
            ret[x][y] = i;
            int val = grid[x][y] == 'R';
            assign[i] -= val;

            if (x + dx >= 0 && x + dx < r) {
                x += dx;
            } else {
                ++y;
                dx = -dx;
            }
        };
        
        visitedAndAssign();
        while (assign[i] > 0) {
            visitedAndAssign();
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (ret[i][j] == -1) {
                ret[i][j] = k - 1;
            }
            std::cout << idxToChar[ret[i][j]];
        }
        std::cout << std::endl;
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (char i = '0'; i <= '9'; ++i) {
        idxToChar.push_back(i);
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        idxToChar.push_back(i);
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        idxToChar.push_back(i);
    }

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}