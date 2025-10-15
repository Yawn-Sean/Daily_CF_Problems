#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    
    vector<string> grid(n);
    int sx, sy, tx, ty;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'T') {
                tx = i;
                ty = j;
            }
        }
    }

    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(3, 0)));

    function<void(int,int,int,int)> dfs = [&](int i, int j, int last_dir, int cnt) {
        for (int k = 0; k < 4; k++) {
            int new_cnt;
            if (k == last_dir) {
                new_cnt = cnt;
            } else {
                new_cnt = cnt + 1;
            }
            int ni = i + dirs[k].first;
            int nj = j + dirs[k].second;
            if (new_cnt <= 2 && ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] != '*' && !vis[ni][nj][new_cnt]) {
                vis[ni][nj][new_cnt] = 1;
                dfs(ni, nj, k, new_cnt);
            } 
        }
    };

    bool ans = false;
    for (int k = 0; k < 4; k++) {
        vis[sx][sy][0] = 1;
        dfs(sx, sy, k, 0);
        ans |= vis[tx][ty][0] || vis[tx][ty][1] || vis[tx][ty][2];
        if (ans) { break; }
        for (auto& v : vis) {
            for (auto& w : v) {
                for (auto& x : w) {
                    x = 0;
                }
            }
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
    return 0;
}
