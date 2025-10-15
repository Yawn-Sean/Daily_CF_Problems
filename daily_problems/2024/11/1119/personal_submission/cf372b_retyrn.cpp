int s[50][50][50][50];
int ps[50][50];
int n, m, q;
using ai4 = array<int, 4>;

void init(int sx, int sy, const std::vector<std::vector<int>>& a) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[sx][sy][i][j] = s[sx][sy][i-1][j] + s[sx][sy][i][j-1] - s[sx][sy][i-1][j-1] + a[i-1][j-1];
        }
    }
}

int sum(int sx, int sy, int x1, int y1, int x2, int y2) {
    if (x1 > x2 or y1 > y2) return 0;
    return s[sx][sy][x2][y2] - s[sx][sy][x1 - 1][y2] - s[sx][sy][x2][y1 - 1] + s[sx][sy][x1 - 1][y1 - 1];
}

int psum(int x1, int y1, int x2, int y2) {
    if (x1 > x2 or y1 > y2) return 0;
    return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
}

void solve() {
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j ++) {
            if (s[j] == '1') a[i][j] = 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + a[i-1][j-1];
        }
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            vector<vector<int>> mat(n, vector<int>(m));
            for (int ii = i; ii < n; ii ++) {
                for (int jj = j; jj < m; jj ++) {
                    int u = psum(i+1, j+1, ii+1, jj+1);
                    if (u) continue;
                    mat[ii][jj] = 1;
                }
            }
            init(i, j, mat);
        }
    }
    
    map<ai4, int> mp;
    
    while (q --) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 --, y1 --, x2 --, y2 --;
        
        if (mp.count({x1, x2, y1, y2})) {
            cout << mp[{x1, x2, y1, y2}] << endl;
            continue;
        }
        
        int ans = 0;
        // 枚举左上角
        for (int i = x1; i <= x2; i ++) {
            for (int j = y1; j <= y2; j ++) {
                ans += sum(i, j, i+1, j+1, x2+1, y2+1);
            }
        }
        mp[{x1, x2, y1, y2}] = ans;
        cout << ans << endl;
    }
}