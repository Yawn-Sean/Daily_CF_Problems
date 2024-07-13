#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m, '.'));
    vector<int> dirs = {-1, 0, 1, 0, -1};

    function<bool(int, int, char)> check = [&] (int i, int j, char c) {
        for (int d = 0; d < 4; d ++)
            if (i + dirs[d] >= 0 && i + dirs[d] < n && j + dirs[d+1] >= 0 && j + dirs[d+1] < m && grid[i+dirs[d]][j+dirs[d+1]] == c)
                return false;
        return true;
    };

    function<bool(int, int, char)> check1 = [&] (int i, int j, char c) {
        for (int d = 0; d < 3; d ++)
            if (i + dirs[d] >= 0 && i + dirs[d] < n && j + dirs[d+1] >= 0 && j + dirs[d+1] < m && grid[i+dirs[d]][j+dirs[d+1]] == c)
                return false;
        return true;
    };

    for (int i = 0; i < n; i ++) 
        for (int j = 0; j < m; j ++)
            if (grid[i][j] == '.') 
                for (char c = 'A'; c <= 'Z'; c ++) {
                    if (check(i, j, c)) {
                        grid[i][j] = c;
                        break;
                    }
                    if (check1(i, j, c)) {
                        int nj = j - 1;
                        while (nj >= 0 && grid[i][nj] == c) nj --;
                        nj ++;
                        int sz = j - nj;

                        if (i + sz >= n) continue;

                        bool flg = true;

                        for (int dx = 0; dx <= sz; dx ++) {
                            if (grid[i+dx][nj+sz] != '.' && grid[i+dx][nj+sz] != c) flg = false;
                            if (grid[i+sz][nj+dx] != '.' && grid[i+sz][nj+dx] != c) flg = false;
                        }

                        if (flg) {
                            for (int dx = 0; dx <= sz; dx ++)
                                grid[i+dx][nj+sz] = c, grid[i+sz][nj+dx] = c;
                            break;
                        }
                    }
                }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) cout << grid[i][j];
        cout << '\n';
    }

    return 0;
}