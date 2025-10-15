int n, m, k;
int f[11][maxn][maxn];
string s, t;

void solve() {
    cin >> n >> m >> k;
    cin >> s >> t;
    
    for (int c = 1; c <= k; c ++) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (s[i-1] == t[j-1]) f[c][i][j] = max(f[c-1][i-1][j-1], f[c][i-1][j-1]) + 1;
            }
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                chmax(f[c][i][j], f[c][i-1][j]);
                chmax(f[c][i][j], f[c][i][j-1]);
            }
        }
    }
    
    cout << f[k][n][m] << endl;
}