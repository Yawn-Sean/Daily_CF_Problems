#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> seen(n, vector<int>(m, 0));
    vector<tuple<int, int, int>> ans; // (row, col, length)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                int ans_len = -1;
                int step = 1;
                int l = j, r = j, u = i, d = i;
                while (true) {
                    l = j - step;
                    r = j + step;
                    u = i - step;
                    d = i + step;
                    if (l < 0 || r >= m || u < 0 || d >= n) {
                        break;
                    }

                    if (grid[u][j] == '*' && grid[d][j] == '*' && 
                        grid[i][l] == '*' && grid[i][r] == '*') {
                        seen[i][l]++;
                        seen[i][r]++;
                        seen[d][j]++;
                        seen[u][j]++;
                        seen[i][j]++;
                        ans_len = step;
                    } else {
                        break;
                    }
                    step++;
                }

                if (ans_len != -1) {
                    ans.emplace_back(i + 1, j + 1, ans_len);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout << seen[i][j];
            if (grid[i][j] == '*' && seen[i][j] == 0) {
                cout << "-1\n";
                return 0;
            }
        }
        // cout << "\n";
    }

    cout << ans.size() << "\n";
    for (auto& [x, y, l]: ans) {
        cout << x << " " << y << " " << l << "\n";
    }
    return 0;
}
