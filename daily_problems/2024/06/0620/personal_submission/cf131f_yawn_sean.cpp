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

    vector<string> grid(n);

    for (int i = 0; i < n; i ++)
        cin >> grid[i];
    
    vector<int> dirs = {-1, 0, 1, 0, -1};
    vector<vector<int>> note(n, vector<int>(m));

    for (int i = 1; i < n - 1; i ++)
        for (int j = 1; j < m - 1; j ++)
            if (grid[i][j] - '0') {
                note[i][j] = 1;
                for (int d = 0; d < 4; d ++)
                    if (grid[i+dirs[d]][j+dirs[d+1]] == '0')
                        note[i][j] = 0;
            }

    long long ans = 0;
    for (int xl = 0; xl < n; xl ++) {
        vector<int> tmp(m);
        for (int xr = xl + 2; xr < n; xr ++) {
            for (int i = 0; i < m; i ++)
                tmp[i] += note[xr-1][i];
            // l, r 表示去掉左右边界后的左右端点
            int l = 1, r = 1, cur = 0;
            while (l < m - 1) {
                while (r < m - 1 && cur < k)
                    cur += tmp[r++];
                if (cur < k) break;
                ans += m - r;
                cur -= tmp[l++];
            }
        }
    }
    cout << ans << '\n';

    return 0;
}