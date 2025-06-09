/*
至多转弯 2 次，其实就是看 S 和 T 分别出发，不转弯，能走到哪些地方
假设 S 能走到的某个格子和 T 能走到的某个格子在同一条横线或者竖线上，则只要再看二者之间能否直接走到即可了
*/

int n, m, block_cnt[N][N];
string s[N];
vector<PII> p1, p2;
 
void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }

    int sx = 0, sy = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }

    for (int i = sx; i > 0; i--) {
        if (s[i][sy] != '*') {
            p1.push_back({i, sy});
        } else {
            break;
        }
    }
    for (int i = sx; i <= n; i++) {
        if (s[i][sy] != '*') {
            p1.push_back({i, sy});
        } else {
            break;
        }
    }

    for (int j = sy; j > 0; j--) {
        if (s[sx][j] != '*') {
            p1.push_back({sx, j});
        } else {
            break;
        }
    }
    for (int j = sy; j <= m; j++) {
        if (s[sx][j] != '*') {
            p1.push_back({sx, j});
        } else {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'T') {
                sx = i;
                sy = j;
            }
        }
    }

    for (int i = sx; i > 0; i--) {
        if (s[i][sy] != '*') {
            p2.push_back({i, sy});
        } else {
            break;
        }
    }
    for (int i = sx; i <= n; i++) {
        if (s[i][sy] != '*') {
            p2.push_back({i, sy});
        } else {
            break;
        }
    }

    for (int j = sy; j > 0; j--) {
        if (s[sx][j] != '*') {
            p2.push_back({sx, j});
        } else {
            break;
        }
    }
    for (int j = sy; j <= m; j++) {
        if (s[sx][j] != '*') {
            p2.push_back({sx, j});
        } else {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            block_cnt[i][j] = block_cnt[i - 1][j] + block_cnt[i][j - 1] + (s[i][j] == '*' ? 1 : 0) - block_cnt[i - 1][j - 1];
        }
    }

    auto get_cnt = [&] (int x_1, int y_1, int x_2, int y_2) -> int {
        return block_cnt[x_2][y_2] - block_cnt[x_1 - 1][y_2] - block_cnt[x_2][y_1 - 1] + block_cnt[x_1 - 1][y_1 - 1];
    };

    bool ok = false;
    for (auto &p : p1) {
        for (auto &q : p2) {
            if (p.x == q.x) {
                int x = p.x;
                int l = min(p.y, q.y), r = max(p.y, q.y);
                if (get_cnt(x, l, x, r) == 0) {
                    ok = true;
                }
            } 
            if (p.y == q.y) {
                int u = min(p.x, q.x), d = max(p.x, q.x);
                int y = p.y;
                if (get_cnt(u, y, d, y) == 0) {
                    ok = true;
                }
            }
        }
    }

    cout << (ok ? "YES" : "NO") << "\n";
}   
