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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0, idx = -1;
    for (int i = 0; i < n - 1; i ++) {
        vector<int> diff;
        for (int j = 0; j < m; j ++)
            diff.emplace_back(grid[j][n - 1] - grid[j][i]);
        sort(diff.begin(), diff.end());

        int cur = 0;
        for (int j = 0; j < m; j ++) {
            cur += diff[j];
            if (cur > 0) break;
            if (j + 1 > ans)
                ans = j + 1, idx = i;
        }
    }

    cout << m - ans << '\n';
    if (ans == 0)
        for (int j = 1; j <= n; j ++) cout << j << ' ';
    else {
        vector<int> st_range(m);
        iota(st_range.begin(), st_range.end(), 0);
        sort(st_range.begin(), st_range.end(), [&](int i, int j) {return grid[i][n - 1] - grid[i][idx] < grid[j][n - 1] - grid[j][idx];});
        for (int i = ans; i < m; i ++) cout << st_range[i] + 1 << ' ';
    }

    return 0;
}