#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) 
            cin >> grid[i][j];

    int ans = k + 1;
    if (m <= k) {
        for (int msk = 0; msk < 1 << (m - 1); msk ++) {
            int res = 0;
            for (int i = 0; i < n; i ++) {
                int cnt = 0;
                for (int j = 0; j < m; j ++)
                    cnt += grid[i][j] == (msk >> j & 1);
                res += min(cnt, m - cnt);
            }
            ans = min(ans, res);
        }
    }
    else {
        for (int i = 0; i < m; i ++) {
            int res = 0;
            for (int j = 0; j < m; j ++) {
                int cnt = 0;
                for (int x = 0; x < n; x ++)
                    cnt += grid[x][j] == grid[x][i];
                res += min(cnt, n - cnt);
            }
            ans = min(ans, res);
        }
    }
    cout << (ans <= k ? ans : -1);

    return 0;
}