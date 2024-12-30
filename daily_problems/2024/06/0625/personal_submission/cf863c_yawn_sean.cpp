#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long k;
    int a, b;
    cin >> k >> a >> b;

    a --, b --;

    vector<vector<int>> grid1(3, vector<int>(3)), grid2(3, vector<int>(3));

    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
            cin >> grid1[i][j], grid1[i][j] --;

    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
            cin >> grid2[i][j], grid2[i][j] --;
    
    vector<vector<int>> grid = {
        {0, 2, 1},
        {1, 0, 2},
        {2, 1, 0}
    };
    
    map<int, int> vis;
    vector<int> acc1 = {0}, acc2 = {0};

    for (int i = 0; i < k; i ++) {
        if (vis.find(a * 3 + b) != vis.end()) {
            int last_vis = vis[a * 3 + b], cycle = i - last_vis;
            long long x = (k - last_vis) / cycle, y = (k - last_vis) % cycle;
            cout << acc1[last_vis] + x * (acc1[i] - acc1[last_vis]) + acc1[last_vis + y] - acc1[last_vis] << ' '\
                 << acc2[last_vis] + x * (acc2[i] - acc2[last_vis]) + acc2[last_vis + y] - acc2[last_vis] << '\n';
            return 0;
        }
        acc1.push_back(acc1[acc1.size() - 1]);
        acc2.push_back(acc2[acc2.size() - 1]);
        if (grid[a][b] == 1) acc1[acc1.size() - 1] ++;
        else if (grid[a][b] == 2) acc2[acc2.size() - 1] ++;
        vis[3 * a + b] = i;
        int tmp_a = a;
        a = grid1[a][b];
        b = grid2[tmp_a][b];
    }
    cout << acc1[k] << ' ' << acc2[k] << '\n';

    return 0;
}