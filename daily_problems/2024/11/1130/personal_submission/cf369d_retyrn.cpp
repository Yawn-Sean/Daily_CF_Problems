int n, k;
int f[maxn][maxn];
// f[i][j] 最小的人是i次小的人是j的存活场面的最小步数

void solve() {
    cin >> n >> k;
    vector<int> p(n);
    cin >> p;
    // 预处理 suf0[i] suf1[i]
    vector<int> suf0(n + 1), suf1(n + 1);
    for (int i = 1; i <= n; i ++) {
        suf0[i] = suf0[i - 1] + (p[n - i] == 0);
        suf1[i] = suf1[i - 1] + (p[n - i] == 100);
    }
    
    mem(f, 0x3f);
    queue<pii> q;
    q.emplace(0, 1);
    f[0][1] = 0;
    
    while (!em(q)) {
        auto [x, y] = q.front();
        q.pop();
        if (y >= n) continue;
        // x 会被自y之后的所有人射击
        // y 会被x射击
        // 1不死 2死 3都可能
        int st_x = (suf1[n - y] > 0 ? 2 : (suf0[n - y] == n - y ? 1 : 3));
        int st_y = (p[x] == 100 ? 2 : (p[x] == 0 ? 1 : 3));
        
        if ((st_x & 2) and (st_y & 2)) {
            // 全死
            if (f[y + 1][y + 2] == inf) {
                f[y + 1][y + 2] = f[x][y] + 1;
                q.emplace(y + 1, y + 2);
            }
        }
        if ((st_x & 2) and (st_y & 1)) {
            // x死 y不死
            if (f[y][y + 1] == inf) {
                f[y][y + 1] = f[x][y] + 1;
                q.emplace(y, y + 1);
            }
        }
        if ((st_x & 1) and (st_y & 2)) {
            // x不死 y死
            if (f[x][y + 1] == inf) {
                f[x][y + 1] = f[x][y] + 1;
                q.emplace(x, y + 1);
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i <= n + 1; i ++) {
        for (int j = i + 1; j <= n + 2; j ++) {
            res += (f[i][j] <= k);
        }
    }
    cout << res << endl;
}