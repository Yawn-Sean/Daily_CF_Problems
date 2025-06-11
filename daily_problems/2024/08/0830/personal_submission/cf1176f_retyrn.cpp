int n;
ll f[maxn][10];

void update(vector<int>& v, int val) {
    if (val > v[0]) {
        v[2] = v[1], v[1] = v[0], v[0] = val;
    }
    else if (val > v[1]) {
        v[2] = v[1], v[1] = val;
    }
    else if (val > v[2]) {
        v[2] = val;
    }
}
void solve() {
    cin >> n;
    mem(f, -0x3f);
    f[0][0] = 0;
    
    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;
        vector<vector<int>> a(4, vector<int>(3, -inf));
        while (k --) {
            int c, d;
            cin >> c >> d;
            update(a[c], d);
        }
        
        for (int j = 0; j < 10; j ++) {
            if (f[i][j] < 0) continue;
            // 不取
            chmax(f[i+1][j], f[i][j]);
            // 取1个
            for (int c = 1; c <= 3; c ++) {
                if (a[c][0] < 0) continue;
                int flag = (j == 9 ? 2 : 1);
                chmax(f[i+1][(j+1) % 10], f[i][j] + a[c][0] * flag);
            }
            // 取2个
            if (a[1][1] > 0) {
                if (j == 8 or j == 9) {
                    chmax(f[i+1][(j+2) % 10], f[i][j] + a[1][0] + a[1][1] + a[1][0]);
                }
                else chmax(f[i+1][(j+2) % 10], f[i][j] + a[1][0] + a[1][1]);
            }
            if (a[1][0] > 0 and a[2][0] > 0) {
                if (j == 8 or j == 9) {
                    chmax(f[i+1][(j+2) % 10], f[i][j] + a[1][0] + a[2][0] + max(a[1][0], a[2][0]));
                }
                else chmax(f[i+1][(j+2) % 10], f[i][j] + a[1][0] + a[2][0]);
            }
            // 取3个
            if (a[1][2] > 0) {
                if (j == 7 or j == 8 or j == 9) {
                    chmax(f[i+1][(j+3) % 10], f[i][j] + a[1][0] + a[1][1] + a[1][2] + a[1][0]);
                }
                else chmax(f[i+1][(j+3) % 10], f[i][j] + a[1][0] + a[1][1] + a[1][2]);
            }
        }
    }
    
    ll res = -inf2;
    for (int i = 0; i < 10; i ++) {
        chmax(res, f[n][i]);
    }
    cout << res << endl;
}