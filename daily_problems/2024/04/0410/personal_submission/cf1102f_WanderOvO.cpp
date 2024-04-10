/*
行数很少，列数很多
枚举行数的排列，然后计算 k 值？
每两行之间的最小差值处理出来，暴力枚举排列，剪枝
*/

int T;
int n, m, a[N][M];
int d[N][N];
int xd[N][N];
int p[N];
int res;
bool vis[N];

void dfs(int u, int mn) {
    if (mn <= res) {
        return;
    }
    if (u > n) {
        int first_row = p[1], last_row = p[n];
        mn = min(mn, xd[first_row][last_row]);
        res = max(res, mn);
        return;
    }
    
    for (int i = n; i > 0; i--) {
        if (!vis[i]) {
            p[u] = i;
            vis[i] = true;
            if (u > 1) {
                if (d[i][p[u - 1]] <= res) {
                    vis[i] = false;
                    continue;    
                }
                dfs(u + 1, min(mn, d[i][p[u - 1]]));
            } else {
                dfs(u + 1, INF);
            }
            vis[i] = false;
        }
    }
}

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {   
            for (int k = 1; k <= m; k++) {
                d[i][j] = min(d[i][j], (int)(abs(a[i][k] - a[j][k])));
            }
            d[j][i] = d[i][j];
        }
    }
    memset(xd, 0x3f, sizeof xd);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            for (int k = 1; k < m; k++) {
                xd[i][j] = min(xd[i][j], (int)(abs(a[i][k + 1] - a[j][k])));
            }
        }
    }
    
    memset(vis, 0, sizeof vis);
    res = 0;
    
    if (n == 1) {
        res = INF;
        for (int i = 2; i <= m; i++) {
            res = min(res, (int)(abs(a[1][i] - a[1][i - 1])));    
        }
        cout << res << "\n";
        return;
    }
    
    dfs(1, INF);
    cout << res << "\n";
}           