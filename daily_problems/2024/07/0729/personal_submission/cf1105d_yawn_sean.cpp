#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    vector<int> speed(p + 1);
    for (int i = 1; i <= p; i ++)
        cin >> speed[i];
    
    function<int(int, int)> f = [&](int x, int y) {
        return x * m + y;
    };

    vector<vector<int>> cur(p + 1);
    vector<string> grid(n);
    vector<int> cnt(p + 1);

    for (auto &x: grid) cin >> x;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] >= '1' && grid[i][j] <= '9')
                cur[grid[i][j] - '0'].emplace_back(f(i, j)), cnt[grid[i][j] - '0'] ++;
        }
    }

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool flg = true;
    while (flg) {
        flg = false;
        for (int i = 1; i <= p; i ++) {
            for (int _ = 0; _ < speed[i]; _ ++) {
                vector<int> ncur;
                for (auto &msk: cur[i]) {
                    int x = msk / m, y = msk % m;
                    for (auto &[dx, dy]: dirs) {
                        if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m && grid[x+dx][y+dy] == '.') {
                            grid[x+dx][y+dy] = '0';
                            cnt[i] ++;
                            ncur.emplace_back(f(x+dx, y+dy));
                        }
                    }
                }
                cur[i] = ncur;
                if (cur[i].size() == 0)
                    break;
            }
            if (cur[i].size() > 0) flg = true;
        }
    }
    for (int i = 1; i <= p; i ++) cout << cnt[i] << ' ';

    return 0;
}