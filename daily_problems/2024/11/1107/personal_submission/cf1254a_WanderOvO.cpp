/*
sum(r * c) <= 2e4, 1.5s, k <= 62
cnt 个包含 rice 的格子，分给 k 只鸡，几乎平均分一定能做到
16 / 6 = 2，16 % 6 = 4，4 个 3 和 2 个 2
如何保证连通？选的时候直接一行一行选，先把第一行走完，再反向走第二行...
*/

string s[M];
int r, c, k;
int cur_x = 0, cur_y = 0;

void color(vector<vector<char>> &grid, char id, int cnt) {
    int colored_cnt = 0;
    for ( ; cur_x < r && colored_cnt < cnt; ) {
        if (cur_x % 2 == 0) {
            for ( ; cur_y < c && colored_cnt < cnt; cur_y++) {
                grid[cur_x][cur_y] = id;
                colored_cnt += (s[cur_x][cur_y] == 'R');
            }
        } else {
            for ( ; cur_y >= 0 && colored_cnt < cnt; cur_y--) {
                grid[cur_x][cur_y] = id;
                colored_cnt += (s[cur_x][cur_y] == 'R');
            }
        }
        if (cur_y < 0) {
            cur_y = 0;
            cur_x++;
        } else if (cur_y >= c) {
            cur_y = c - 1;
            cur_x++;
        }
    }
}

void meibao() {
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        cin >> s[i];
    }
    vector<char> ids;
    for (char ch = '0'; ch <= '9'; ch++) {
        ids.pb(ch);
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        ids.pb(ch);
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        ids.pb(ch);
    }
    int cntr = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cntr += s[i][j] == 'R';
        }
    }
    int avg = cntr / k;
    int avg_cnt = k - cntr % k, more_cnt = cntr % k;
    vector<vector<char>> res(r, vector<char>(c, 0));
    cur_x = 0;
    cur_y = 0;
    for (int i = 0; i < k; i++) {
        color(res, ids[i], avg + (i >= avg_cnt ? 1 : 0));
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (res[i][j] == '\0') {
                res[i][j] = ids[k - 1];
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << res[i][j];
        }
        cout << "\n";
    }
}
