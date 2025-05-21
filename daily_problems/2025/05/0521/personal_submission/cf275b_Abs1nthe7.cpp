#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<pair<int, int>> blacks;
    
    // 预处理行和列的前缀和
    vector<vector<int>> row_sum(n, vector<int>(m + 1));
    vector<vector<int>> col_sum(m, vector<int>(n + 1));
    
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            row_sum[i][j + 1] = row_sum[i][j] + (grid[i][j] == 'B');
            if (grid[i][j] == 'B') {
                blacks.emplace_back(i, j);
            }
        }
    }
    
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            col_sum[j][i + 1] = col_sum[j][i] + (grid[i][j] == 'B');
        }
    }
    
    auto check_row = [&](int x, int y1, int y2) {
        if (y1 > y2) swap(y1, y2);
        return (row_sum[x][y2 + 1] - row_sum[x][y1] == y2 - y1 + 1);
    };
    
    auto check_col = [&](int y, int x1, int x2) {
        if (x1 > x2) swap(x1, x2);
        return (col_sum[y][x2 + 1] - col_sum[y][x1] == x2 - x1 + 1);
    };
    
    for (auto& [x1, y1] : blacks) {
        for (auto& [x2, y2] : blacks) {
            if (x1 == x2 && y1 == y2) continue;
            
            // 条件1: 同一行且中间全黑
            if (x1 == x2 && check_row(x1, y1, y2)) continue;
            
            // 条件2: 同一列且中间全黑
            if (y1 == y2 && check_col(y1, x1, x2)) continue;
            
            // 条件3: 拐点C(x1,y2)存在且路径全黑
            if (grid[x1][y2] == 'B' && check_row(x1, y1, y2) && check_col(y2, x1, x2)) continue;
            
            // 条件4: 拐点D(x2,y1)存在且路径全黑
            if (grid[x2][y1] == 'B' && check_col(y1, x1, x2) && check_row(x2, y1, y2)) continue;
            
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    return 0;
}
