#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std; 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &line: grid)
        cin >> line;

    vector<vector<int>> cnt(n, vector<int>(m, 0));
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    string chars = "v<^>";

    auto check = [&] (int i, int j) -> bool {
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.';
    };

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '.') {
                for (auto &[di, dj]: dirs)
                    if (check(i + di, j + dj))
                        cnt[i][j] ++;
            }
        }
    }

    auto dfs = [&] (auto &self, int i, int j) -> void {
        for (int didx = 0; didx < 4; didx ++) {
            int ni = i + dirs[didx].first, nj = j + dirs[didx].second;
            if (check(ni, nj)) {
                cnt[i][j] = 0;
                cnt[ni][nj] = 0;

                grid[i][j] = chars[didx];
                grid[ni][nj] = chars[didx ^ 2];


                for (auto &[dx, dy]: dirs) {
                    if (check(ni + dx, nj + dy)) {
                        cnt[ni + dx][nj + dy] --;
                        if (cnt[ni + dx][nj + dy] == 1)
                            self(self, ni + dx, nj + dy);
                    }
                }
                return ;
            }
        }
    };

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (cnt[i][j] == 1) {
                dfs(dfs, i, j);
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '.') {
                return cout << "Not unique", 0;
            }
        }
    }

    for (auto &line: grid) cout << line << '\n';

    return 0;
}