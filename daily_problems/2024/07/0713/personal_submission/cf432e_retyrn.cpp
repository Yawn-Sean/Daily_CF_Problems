int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int get(int x, int y) {
    if (x > y) swap(x, y);
    if (x == 0 and y == 0) return 1;
    if (x == 0 and y == 1) return 2;
    if (x == 0) return 1;
    return 0;
}

int get(vector<string>& g, int x, int y) {
    vector<int> cnt(6, 0);
    for (int i = 0; i < 4; i ++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 and nx < n and ny >= 0 and ny < m and g[nx][ny] != '#') {
            cnt[g[nx][ny]-'A'] = 1;
        }
    }
    for (int i = 0; i < 6; i ++) {
        if (!cnt[i]) return i;
    }
    return 6;
}


void solve() {
    cin >> n >> m;
    vector<string> g(n, string(m, '#'));
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (g[i][j] != '#') continue;
            
            int u = get(g, i, j);
            int len = 1, mx = min(n - i, m - j);
            
            while (len < mx and g[i][j+len] == '#' and get(26, (i?g[i-1][j+len]-'A': 26)) == u) {
                len++;
            }
            
            // dbg(i, j, len, mx);
            
            for (int ii = i; ii < i + len; ii ++) {
                for (int jj = j; jj < j + len; jj ++) {
                    g[ii][jj] = 'A' + u;
                }
            }
        }
    }
    
    for (auto& ss : g) {
        cout << ss << endl;
    }
}