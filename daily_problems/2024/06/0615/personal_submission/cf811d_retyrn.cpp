int n, m;
string s = "LRUD";
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pii move(char c) {
    cout << c << endl;
    cout.flush();
    auto res = mpr(0, 0);
    cin >> res.fi >> res.se;
    res.fi -= 1;
    res.se -= 1;
    return res;
}
void solve() {
    cin >> n >> m;
    vector<string> g(n);
    cin >> g;
    int x = 0, y = 0;
    if (m > 1 and g[0][1] != '*') {
        pii pos = move('R');
        if (pos.fi == 0 and pos.se == 0) {
            swap(s[0], s[1]);
            move('L');
        }
        x = 0, y = 1;
        if (g[x][y] == 'F') return;
        if (n == 1) {
            while (g[x][y] != 'F') {
                auto t = move(s[1]);
                x = t.fi, y = t.se;
            }
            return;
        }
        int idx = 0;
        while (g[1][idx] == '*') idx ++;
        while (y > idx) {
            auto t = move(s[0]);
            x = t.fi, y = t.se;
            if (g[x][y] == 'F') return;
        }
        while (y < idx) {
            auto t = move(s[1]);
            x = t.fi, y = t.se;
            if (g[x][y] == 'F') return;
        }
        // dbg(idx, x, y);
        auto t = move('D');
        if (t.fi == x and t.se == y) {
            swap(s[2], s[3]);
            t = move('U');
            x = t.fi, y = t.se;
        }
        else {
            x = t.fi, y = t.se;
        }
    }
    else {
        pii pos = move('D');
        if (pos.fi == 0 and pos.se == 0) {
            swap(s[2], s[3]);
            move('U');
        }
        x = 1, y = 0;
        if (g[x][y] == 'F') return;
        if (m == 1) {
            while (g[x][y] != 'F') {
                auto t = move(s[3]);
                x = t.fi, y = t.se;
            }
            return;
        }
        int idx = 0;
        while (g[idx][1] == '*') idx ++;
        while (x > idx) {
            auto t = move(s[2]);
            x = t.fi, y = t.se;
            if (g[x][y] == 'F') return;
        }
        while (x < idx) {
            auto t = move(s[3]);
            x = t.fi, y = t.se;
            if (g[x][y] == 'F') return;
        }
        auto t = move('R');
        if (t.fi == x and t.se == y) {
            swap(s[0], s[1]);
            t = move('L');
            x = t.fi, y = t.se;
        }
        else {
            x = t.fi, y = t.se;
        }
    }
    
    pii fp = {-1, -1};
    for (int i = 0; i < n and fp.fi < 0; i ++) {
        for (int j = 0; j < m and fp.fi < 0; j ++) {
            if (g[i][j] == 'F') {
                fp.fi = i, fp.se = j;
                break;
            }
        }
    }
    
    // bfs
    vector<vector<pii>> to(n, vector<pii>(m, mpr(-1, -1)));
    queue<pii> q;
    q.push(fp);
    while (!em(q)) {
        auto [xx, yy] = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m or g[nx][ny] != '.' or to[nx][ny].fi >= 0) continue;
            to[nx][ny].fi = xx;
            to[nx][ny].se = yy;
            q.emplace(nx, ny);
        }
    }
    
    while (g[x][y] != 'F') {
        auto [xx, yy] = to[x][y];
        if (xx - x == 1) {
            move(s[3]);
        }
        else if (xx - x == -1) {
            move(s[2]);
        }
        else if (yy - y == 1) {
            move(s[1]);
        }
        else {
            move(s[0]);
        }
        x = xx, y = yy;
    }
    
}