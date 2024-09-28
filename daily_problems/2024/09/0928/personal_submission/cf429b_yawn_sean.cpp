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

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp0(n, vector<int>(m, 0)), dp1(n, vector<int>(m, 0)), dp2(n, vector<int>(m, 0)), dp3(n, vector<int>(m, 0));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int x = 0;
            if (i > 0) x = max(x, dp0[i - 1][j]);
            if (j > 0) x = max(x, dp0[i][j - 1]);
            dp0[i][j] = x + grid[i][j];
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = m - 1; j >= 0; j --) {
            int x = 0;
            if (i > 0) x = max(x, dp1[i - 1][j]);
            if (j < m - 1) x = max(x, dp1[i][j + 1]);
            dp1[i][j] = x + grid[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i --) {
        for (int j = 0; j < m; j ++) {
            int x = 0;
            if (i < n - 1) x = max(x, dp2[i + 1][j]);
            if (j > 0) x = max(x, dp2[i][j - 1]);
            dp2[i][j] = x + grid[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i --) {
        for (int j = m - 1; j >= 0; j --) {
            int x = 0;
            if (i < n - 1) x = max(x, dp3[i + 1][j]);
            if (j < m - 1) x = max(x, dp3[i][j + 1]);
            dp3[i][j] = x + grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i ++) {
        for (int j = 1; j < m - 1; j ++) {
            ans = max(ans, dp0[i - 1][j] + dp1[i][j + 1] + dp2[i][j - 1] + dp3[i + 1][j]);
            ans = max(ans, dp0[i][j - 1] + dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j + 1]);
        }
    }
    cout << ans;

    return 0;
}