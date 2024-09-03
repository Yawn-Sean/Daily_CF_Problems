#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    vector<vector<int>> dp(n, vector<int>(n, 2 * n));
    dp[0][0] = 0;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i && dp[i-1][j] < dp[i][j]) dp[i][j] = dp[i-1][j];
            if (j && dp[i][j-1] < dp[i][j]) dp[i][j] = dp[i][j-1];
            dp[i][j] += grid[i][j] != 'a';
        }
    }

    int cur = 0;
    vector<pair<int, int>> tmp = {{0, 0}};

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (dp[i][j] <= k) {
                if (i + j > cur) {
                    cur = i + j;
                    tmp.clear();
                    tmp.emplace_back(i, j);
                }
                else if (i + j == cur) {
                    tmp.emplace_back(i, j);
                }
            }
        }
    }

    cout << string(cur, 'a');
    auto [x, y] = tmp[0];
    cout << (dp[x][y] <= k ? 'a' : grid[x][y]);

    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}};
    for (int i = cur + 1; i < 2 * n - 1; i ++) {
        vector<pair<int, int>> ntmp;
        char nc = 'z' + 1;
        for (auto &[x, y]: tmp) {
            for (auto &[dx, dy]: dirs) {
                if (x + dx < n && y + dy < n) {
                    if (grid[x+dx][y+dy] < nc) {
                        nc = grid[x+dx][y+dy];
                        ntmp.clear();
                        ntmp.emplace_back(x+dx, y+dy);
                    }
                    else if (grid[x+dx][y+dy] == nc && ntmp.back().first != x+dx) {
                        ntmp.emplace_back(x+dx, y+dy);
                    }
                }
            }
        }
        cout << nc;
        tmp = ntmp;
    }

    return 0;
}