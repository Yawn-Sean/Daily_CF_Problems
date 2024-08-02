int n, m;
string g[N];
a2 vis[N][N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool ok = 0;
void dfs(int x, int y) {
    if (ok) return;
    for (int i = 0; i < 4; i ++) {
        int nx = (x + dx[i]);
        int ny = (y + dy[i]);
        int px = (nx % n + n) % n;
        int py = (ny % m + m) % m;
        if (g[px][py] == '#') continue;
        if (vis[px][py][0] == INT_MAX) {
            vis[px][py] = {nx, ny};
            dfs(nx, ny);
        } else if (vis[px][py][0] != nx || vis[px][py][1] != ny) {
            ok = 1;
            return;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            vis[i][j] = {INT_MAX, INT_MAX};
        }
    }
    for (int i = 0; i < n; i ++) {
        cin >> g[i];
    }
    a2 st = {0, 0};
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == 'S') {
                st = {i, j};
                vis[i][j] = {i, j};
                g[i][j] = '.';
                break;
            }
        }
    }
    dfs(st[0], st[1]);
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}
