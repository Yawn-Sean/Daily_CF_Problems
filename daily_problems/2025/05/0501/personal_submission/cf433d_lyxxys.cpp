void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n,vector<int>(m));
    vector<vector<int>> f1(n,vector<int>(m)), f2(n,vector<int>(m)), f3(n,vector<int>(m)), f4(n,vector<int>(m));

    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            cin >> g[i][j];
        }
    }
    auto upd_up_down = [&](int col)->void{
        int cur, i;
        for (i = 0, cur = 0; i < n; ++ i){
            cur = g[i][col] ? cur+1 : 0;
            f1[i][col] = cur;
        }
        for (i = n-1, cur = 0; i >= 0; -- i){
            cur = g[i][col] ? cur+1 : 0;
            f2[i][col] = cur;
        }
    };
    auto upd_left_right = [&](int row)->void{
        int cur, i;
        for (i = 0, cur = 0; i < m; ++ i){
            cur = g[row][i] ? cur+1 : 0;
            f3[row][i] = cur;
        }
        for (i = m-1, cur = 0; i >= 0; -- i){
            cur = g[row][i] ? cur+1 : 0;
            f4[row][i] = cur;
        }
    };
    auto pick_up_down = [&](int row, int col)->int{  // 贪心枚举左右方向 来找 上边界和下边界
        if (!g[row][col]) return 0;
        int i = col, j = col, res = max(f1[row][col], f2[row][col]), mi = f1[row][col];

        while (i-1 >= 0 || j+1 < m){  // 考虑下边界的情况
            if (i-1 >= 0 && j+1 < m && f1[row][i-1] > f1[row][j+1] || j == m-1){
                i -= 1;
                fmin(mi, f1[row][i]);
            } else {
                j += 1;
                fmin(mi, f1[row][j]);
            }
            if (mi == 0) break;
            fmax(res, mi * (j-i+1));
        }

        mi = f2[row][col], i = col, j = col;
        while (i-1 >= 0 || j+1 < m){  // 考虑上边界的情况
            if (i-1 >= 0 && j+1 < m && f2[row][i-1] > f2[row][j+1] || j == m-1){
                i -= 1;
                fmin(mi, f2[row][i]);
            } else {
                j += 1;
                fmin(mi, f2[row][j]);
            }
            if (mi == 0) break;
            fmax(res, mi * (j-i+1));
        }

        return res;
    };
    auto pick_left_right = [&](int row, int col)->int{  // 贪心枚举上下方向 来找 左边界和右边界
        if (!g[row][col]) return 0;
        int i = row, j = row, res = max(f3[row][col], f4[row][col]), mi = f3[row][col];

        while (i-1 >= 0 || j+1 < n){
            if (i-1 >= 0 && j+1 < n && f3[i-1][col] > f3[j+1][col] || j == n-1){
                i -= 1;
                fmin(mi, f3[i][col]);
            } else {
                j += 1;
                fmin(mi, f3[j][col]);
            }
            if (mi == 0) break;
            fmax(res, mi * (j-i+1));
        }

        mi = f4[row][col], i = row, j = row;
        while (i-1 >= 0 || j+1 < n){
            if (i-1 >= 0 && j+1 < n && f4[i-1][col] > f4[j+1][col] || j == n-1){
                i -= 1;
                fmin(mi, f4[i][col]);
            } else {
                j += 1;
                fmin(mi, f4[j][col]);
            }
            if (mi == 0) break;
            fmax(res, mi * (j-i+1));
        }

        return res;
    };
    
    for (int i = 0; i < n; ++ i){
        upd_left_right(i);
    }
    for (int i = 0; i < m; ++ i){
        upd_up_down(i);
    }

    while (q--){
        int type, x, y;
        cin >> type >> x >> y;
        x -= 1, y -= 1;
        if (type == 1){
            g[x][y] = !g[x][y];
            upd_up_down(y);
            upd_left_right(x);
        } else {
            int res = max(pick_left_right(x, y), pick_up_down(x, y));
            cout << res << "\n";
        }
    }
}
