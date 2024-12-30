int n, q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
    cin >> n >> q;
    int d = 100;
    vector<vector<int>> f(d * 2, vector<int>(d * 2, 0));
    f[d][d] = n;
    
    function<void(int, int)> dfs = [&](int x, int y) {
        if (f[x + d][y + d] <= 3) return;
        int a = f[x + d][y + d] / 4;
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            f[nx + d][ny + d] += a;
        }
        f[x + d][y + d] %= 4;
        
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            dfs(nx, ny);
        }
    };
    
    dfs(0, 0);
    
    while (q --) {
        int x, y;
        cin >> x >> y;
        if (abs(x) >= d or abs(y) >= d) {
            cout << 0 << endl;
        }
        else {
            cout << f[x + d][y + d] << endl;
        }
    }
    
}