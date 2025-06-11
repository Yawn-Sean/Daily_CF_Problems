int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
using ai3 = array<int, 3>;

void solve() {
    cin >> n >> m;
    vector<string> g(n);
    cin >> g;
    pii start{-1, -1};
    
    for (int i = 0; i < n and start.fi == -1; i ++) {
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == 'S') {
                start = mpr(i, j);
                g[i][j] = '.';
                break;
            }
        }
    }
    
    // bfs
    vector<vector<pii>> f(n, vector<pii>(m, mpr(inf, inf)));
    // 记录每个位置最先到达的坐标
    
    queue<pii> q;
    f[start.fi][start.se] = start;
    q.push(start);
    
    while (!em(q)) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i], ny = y + dy[i];
            int px = (nx % n + n) % n;
            int py = (ny % m + m) % m;
            if (g[px][py] == '#') continue;
            if (f[px][py].fi == nx and f[px][py].se == ny) continue;
            if (f[px][py].fi == inf) {
                f[px][py].fi = nx, f[px][py].se = ny;
                q.emplace(nx, ny);
                continue;
            }
            cout << "Yes" << endl;
            return;
        }
    }
    
    cout << "No" << endl;
}