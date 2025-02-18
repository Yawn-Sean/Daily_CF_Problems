/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-30 14:56 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    vector idx = {0, 0, 1, -1}, idy = {1, -1, 0, 0};
    string c = "<>^v";
    vector cnt(n, vector(m, 0));
    for (int i = 0; i < n; i ++) {
        cin >> mp[i];
    }
    auto check = [&] (int x, int y) -> bool {
        if (x < 0 || y < 0 || x >= n || y >= m) return false;
        if (mp[x][y] != '.') return false;
        return true;
    };
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            for (int k = 0; k < 4; k ++) {
                if (check(i + idx[k], j + idy[k])) {
                    cnt[i][j] ++;
                }
            }
        }
    }
    std::function<void (int, int)> dfs = [&] (int nowx, int nowy) {
        // debug("nowx:", nowx, "nowy:", nowy);
        for (int i = 0; i < 4; i ++) {
            int x = nowx + idx[i], y = nowy + idy[i];
            if (check(x, y)) {
                mp[nowx][nowy] = c[i];
                mp[x][y] = c[i ^ 1]; 
                cnt[nowx][nowy] --;
                cnt[x][y] --;
                for (int j = 0; j < 4; j ++) {
                    int sx = x + idx[j], sy = y + idy[j];
                    if (check(sx, sy)) {
                        cnt[sx][sy] --;
                        if (cnt[sx][sy] == 1) {
                            dfs(sx, sy);
                        }
                    }
                }
            }
        }
    };
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (cnt[i][j] == 1 && mp[i][j] == '.') {
                dfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (mp[i][j] == '.') {
                cout << "Not unique" << "\n";
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i ++) cout << mp[i] << "\n";
    return 0;
}

#endif

/*

*/
