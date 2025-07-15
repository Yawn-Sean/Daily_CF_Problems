#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c, 0));

    // '/' change
    map<pair<int,int>, pair<int,int>> dir1;
    dir1[{1, 0}] = {0, -1};
    dir1[{-1, 0}] = {0, 1};  // down-right
    dir1[{0, 1}] = {-1, 0};
    dir1[{0, -1}] = {1, 0}; 

    // '\\' change
    map<pair<int,int>, pair<int,int>> dir2;
    dir2[{1, 0}] = {0, 1};   // down-left
    dir2[{-1, 0}] = {0, -1}; // up
    dir2[{0, 1}] = {1, 0};
    dir2[{0, -1}] = {-1, 0}; // up-right

    int tot = 0;
    vector<string> answers;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                grid[i][j] = 0;
            } else if (c == '\\') {
                grid[i][j] = 2;
                ++tot;
            } else {
                grid[i][j] = 1;
                ++tot;
            }
        }
    }

    vector<vector<int>> vis(r, vector<int>(c, 0));
    auto check = [&](int x, int y, int dx, int dy, char pos) {
        int cnt = 0;
        int old_x = x, old_y = y;
        int old_dx = dx, old_dy = dy;
        while (x >= 0 && x < r && y >= 0 && y < c) {
            if (x < 0 || x >= r || y < 0 || y >= c) {
                break;
            }
            // cout << "Visiting: (" << x << ", " << y << ") with direction (" << dx << ", " << dy << ")" << endl;
            if (vis[x][y] == 0 && grid[x][y] != 0) {
                // cout << x << ' ' << y << endl;
                ++cnt;
            }
            vis[x][y] = 1;
            if (grid[x][y] == 2) {
                auto [nx, ny] = dir2[{dx, dy}];
                dx = nx;
                dy = ny;
            } else if (grid[x][y] == 1) {
                auto [nx, ny] = dir1[{dx, dy}];
                dx = nx;
                dy = ny;
            }
            x += dx;
            y += dy;
        }

        x = old_x, y = old_y;
        dx = old_dx, dy = old_dy;
        while (x >= 0 && x < r && y >= 0 && y < c) {
            if (x < 0 || x >= r || y < 0 || y >= c) {
                break;
            }
            
            vis[x][y] = 0;
            if (grid[x][y] == 2) {
                auto [nx, ny] = dir2[{dx, dy}];
                dx = nx;
                dy = ny;
            } else if (grid[x][y] == 1) {
                auto [nx, ny] = dir1[{dx, dy}];
                dx = nx;
                dy = ny;
            }
            x += dx;
            y += dy;
        }

        x = old_x, y = old_y;
        dx = old_dx, dy = old_dy;
        // cout << cnt << ' ' << tot << endl;
        if (cnt == tot) {
            string ans;
            ans += pos;
            if (pos == 'N' || pos == 'S') {
                ans += to_string(y + 1);
            } else {
                ans += to_string(x + 1);
            }
            answers.push_back(ans);
        }

    };

    for (int i = 0; i < r; i++) {
        check(i, 0, 0, 1, 'W');
        check(i, c - 1, 0, -1, 'E');
    }

    for (int j = 0; j < c; j++) {
        check(0, j, 1, 0, 'N');
        check(r - 1, j, -1, 0, 'S');
    }

    cout << answers.size() << endl;
    for (auto& ans : answers) {
        cout << ans << ' ';
    }
    return 0;
}
