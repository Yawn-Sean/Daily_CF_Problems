#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

struct Operation {
    int r1, c1, r2, c2;
};

void run_test_case() {
    int n, m;
    cin >> n >> m;

    vector<string> grid1(n), grid2(n);
    for (auto &s : grid1) cin >> s;
    for (auto &s : grid2) cin >> s;
    const char XOR_MASK = '#' ^ '.';
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) & 1) {
                grid1[i][j] ^= XOR_MASK;
                grid2[i][j] ^= XOR_MASK;
            }
        }
    }

    vector<pair<int, int>> p1; 
    vector<pair<int, int>> p2; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid1[i][j] != grid2[i][j]) {
                if (grid1[i][j] == '#') p1.emplace_back(i, j);
                else p2.emplace_back(i, j);
            }
        }
    }

    if (p1.size() != p2.size()) {
        cout << -1 << '\n';
        return;
    }

    vector<Operation> ops;

    auto go = [&](pair<int, int> v1, pair<int, int> v2) {
        auto [x1, y1] = v1;
        auto [x2, y2] = v2;

        int dx = (x2 >= x1 ? 1 : -1);
        int dy = (y2 >= y1 ? 1 : -1);

        int x = x1, y = y1;
        vector<pair<int, int>> cur;
        cur.emplace_back(x, y);

        while (x != x2) {
            x += dx;
            if (grid1[x][y] == '.') {
                cur.emplace_back(x, y);
                for (int i = cur.size() - 1; i > 0; i--) {
                    auto [vx1, vy1] = cur[i];
                    auto [vx2, vy2] = cur[i - 1];
                    swap(grid1[vx1][vy1], grid1[vx2][vy2]);
                    ops.push_back({vx1, vy1, vx2, vy2});
                }
                cur.clear();
            }
            cur.emplace_back(x, y);
        }

        while (y != y2) {
            y += dy;
            if (grid1[x][y] == '.') {
                cur.emplace_back(x, y);
                for (int i = cur.size() - 1; i > 0; i--) {
                    auto [vx1, vy1] = cur[i];
                    auto [vx2, vy2] = cur[i - 1];
                    swap(grid1[vx1][vy1], grid1[vx2][vy2]);
                    ops.push_back({vx1, vy1, vx2, vy2});
                }
                cur.clear();
            }
            cur.emplace_back(x, y);
        }
    };

    for (size_t i = 0; i < p1.size(); i++) {
        go(p1[i], p2[i]);
    }

    cout << ops.size() << '\n';

    for (const auto& op : ops) {
        cout << op.r1 + 1 << ' ' << op.c1 + 1 << ' ' 
             << op.r2 + 1 << ' ' << op.c2 + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        run_test_case();
    }

    return 0;
}
