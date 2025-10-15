const int M = 1 << 11;
int n, m;
int f[210][11][M];
int pre[210][11], suf[210][11];

void solve() {
    const int M = 1 << 11;
    // k最大为10
    cin >> n;
    vector<string> a(n);
    vector<int> len(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        len[i] = sz(a[i]);
        for (int l = 0; l < sz(a[i]); l ++) {
            int st = 0;
            for (int r = l; r < l + 10 and r < sz(a[i]); r ++) {
                st = st << 1 | (a[i][r] - '0');
                f[i][r-l+1][st] = 1;
            }
        }
        // 预处理前后缀
        int st = 0;
        for (int j = 0; j < 10 and j < sz(a[i]); j ++) {
            st = st << 1 | (a[i][j] - '0');
            pre[i][j+1] = st;
        }
        st = 0;
        for (int j = sz(a[i]) - 1; j >= sz(a[i]) - 10 and j >= 0; j --) {
            st |= (a[i][j] - '0') << (sz(a[i]) - j - 1);
            suf[i][sz(a[i])-j] = st;
        }
    }
    cin >> m;
    int idx = n;
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        for (int k = 1; k <= 10; k ++) {
            for (int i = 0; i < M; i ++) {
                f[idx][k][i] = f[x][k][i] | f[y][k][i];
            }
        }
        len.push_back(min(inf, len[x] + len[y]));
        // 计算接缝处
        for (int k = 2; k <= 10; k ++) {
            // 枚举前面的长度
            for (int k1 = max(1, k - len[y]); k1 < k and k1 <= len[x]; k1 ++) {
                int k2 = k - k1;
                int st = suf[x][k1] << k2 | pre[y][k2];
                f[idx][k][st] = 1;
            }
        }
        
        // 更新前后缀
        for (int k = 1; k <= 10 and k <= len[idx]; k ++) {
            if (k <= len[x]) pre[idx][k] = pre[x][k];
            else {
                pre[idx][k] = pre[x][len[x]] << (k - len[x]) | pre[y][k - len[x]];
            }
        }
        for (int k = 1; k <= 10 and k <= len[idx]; k ++) {
            if (k <= len[y]) suf[idx][k] = suf[y][k];
            else {
                suf[idx][k] = suf[x][k - len[y]] << len[y] | suf[y][len[y]];
            }
        }
        
        int ans = 0;
        for (int k = 1; k <= 10; k ++) {
            bool ok = true;
            for (int t = 0; t < (1 << k); t ++) {
                if (!f[idx][k][t]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans ++;
        }
        cout << ans << endl;
        idx ++;
    }
    
}