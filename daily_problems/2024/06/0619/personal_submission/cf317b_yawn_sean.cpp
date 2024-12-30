#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> grid(151, vector<int>(151));
    vector<int> dirs = {-1, 0, 1, 0, -1};
    grid[75][75] = n;

    while (true) {
        bool flg = true;

        for (int i = 0; i <= 150; i ++) 
            for (int j = 0; j <= 150; j ++) 
                if (grid[i][j] >= 4) {
                    int v = grid[i][j] / 4;
                    grid[i][j] %= 4;
                    for (int di = 0; di < 4; di ++) {
                        int dx = dirs[di], dy = dirs[di+1];
                        grid[i+dx][j+dy] += v;
                        flg = false;
                    }
                }

        if (flg) break;
    }

    int q;
    cin >> q;
    
    while (q --) {
        int x, y;
        cin >> x >> y;
        if (abs(x) > 75 || abs(y) > 75) cout << "0\n";
        else {
            x += 75;
            y += 75;
            cout << grid[x][y] << '\n';
        }
    }

    return 0;
}