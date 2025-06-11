int n;
int f[10][1<<10][1<<10];

void solve() {
    cin >> n;
    f[0][0][0] = 1;
    
    for (int i = 1; i <= n; i ++) {
        int len = (1 << (i - 1));
        for (int j = 0; j < len; j ++) {
            for (int k = 0; k < len; k ++) {
                f[i][j][k << 1] = f[i][j][k << 1 | 1] = f[i-1][j][k];
            }
        }
        for (int j = len; j < len * 2; j ++) {
            for (int k = 0; k < len * 2; k ++) {
                f[i][j][k] = ((k & 1) ? -f[i][j-len][k] : f[i][j-len][k]);
            }
        }
    }
    
    int len = (1 << n);
    for (int i = 0; i < len; i ++) {
        string s;
        for (int j = 0; j < len; j ++) {
            s += (f[n][i][j] > 0 ? '+' : '*');
        }
        cout << s << endl;
    }
}