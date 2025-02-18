int n, a, b;
int f[210][40010][2]; // f[i][j][k] 到第i个 红色面积是j的 最后一个是颜色k的

void solve() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    cin >> a >> b;
    vector<int> h(n);
    cin >> h;
    vector<int> s(all(h));
    for (int i = 1; i < n; i ++) {
        s[i] += s[i-1];
    }
    if (s[n-1] > a + b) {
        cout << -1 << endl;
        return;
    }
    
    mem(f, 0x3f);
    if (h[0] <= a) f[0][h[0]][0] = 0;
    if (h[0] <= b) f[0][0][1] = 0;

    for (int i = 1; i < n; i ++) {
        for (int j = max(0, s[i] - b); j <= a and j <= s[i]; j ++) {
            if (j >= h[i]) {
                // 0 -> 0
                chmin(f[i][j][0], f[i-1][j-h[i]][0]);
                // 1 -> 0
                chmin(f[i][j][0], f[i-1][j-h[i]][1] + min(h[i], h[i-1]));
            }
            if (s[i] - j >= h[i]) {
                // 0 -> 1
                chmin(f[i][j][1], f[i-1][j][0] + min(h[i], h[i-1]));
                // 1 -> 1
                chmin(f[i][j][1], f[i-1][j][1]);
            }
            
        }
    }
    
    int res = inf;
    for (int i = max(0, s[n-1] - b); i <= a and i <= s[n-1]; i ++) {
        chmin(res, f[n-1][i][0]);
        chmin(res, f[n-1][i][1]);
    }
    cout << (res == inf ? -1 : res) << endl;
}