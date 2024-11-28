int n, m, k;
using al4 = array<ll, 4>;
using pil = pair<int, ll>;

ll f[55][55][110];
pii from[55][55][110];
// f[i][j][k] 选了i门课 以a[j]结尾 最后一天作业量是a[j][0] + k

void solve() {
    cin >> n >> m >> k;
    vector<al4> a(m);
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < 3; j ++) {
            cin >> a[i][j];
        }
        a[i][3] = i + 1;
    }
    sort(all(a), [](al4& x, al4& y) {
        return x[2] < y[2];
    });
    mem(f, -0x3f);
    
    for (int i = 0; i < m; i ++ ) {
        for (int j = 0; j <= a[i][1] - a[i][0]; j ++) {
            f[1][i][j] = j + a[i][0];
        }
    }
    
    for (int i = 2; i <= n; i ++) {
        for (int j = i - 1; j < m; j ++) {
            for (int t = 0; t <= a[j][1] - a[j][0]; t ++) {
                for (int jj = 0; jj < j and a[jj][2] < a[j][2]; jj ++) {
                    ll cur = a[j][0] + t;
                    if (cur - k >= a[jj][0] and cur - k <= a[jj][1] and f[i][j][t] < f[i-1][jj][cur-k-a[jj][0]] + cur) {
                        f[i][j][t] = f[i-1][jj][cur-k-a[jj][0]] + cur;
                        from[i][j][t] = mpr(jj, cur - k - a[jj][0]);
                    }
                    if (cur % k == 0 and cur / k >= a[jj][0] and cur / k <= a[jj][1] and f[i][j][t] < f[i-1][jj][cur/k-a[jj][0]] + cur) {
                        f[i][j][t] = f[i-1][jj][cur/k-a[jj][0]] + cur;
                        from[i][j][t] = mpr(jj, cur / k - a[jj][0]);
                    }
                }
            }
        }
    }
    
    ll mx = 0;
    pii ans = {0, 0};
    vector<pil> path;
    
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j <= 100; j ++) {
            if (f[n][i][j] > mx) {
                mx = f[n][i][j];
                ans = mpr(i, j);
            }
        }
    }
    
    if (mx == 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    // dbg(mx);
    
    while (n > 0) {
        int x = ans.fi, y = ans.se;
        ll cur = a[x][0] + y;
        path.emplace_back(a[x][3], cur);
        ans = from[n][x][y];
        n -= 1;
    }
    
    reverse(all(path));
    
    for (auto& p : path) {
        cout << p << endl;
    }
}