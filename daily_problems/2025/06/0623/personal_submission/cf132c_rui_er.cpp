const int N = 105;

string s;
int n, m, f[N][N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s >> m;
    n = s.size();
    s = " " + s;
    memset(f, 0xc0, sizeof(f));
    f[0][0][0] = f[0][0][1] = 0;
    rep(i, 1, n) {
        rep(j, 0, m) {
            if(j >= 2) {
                chkmax(f[i][j][0], f[i][j - 2][0]);
                chkmax(f[i][j][1], f[i][j - 2][1]);
            }
            if(s[i] == 'F') {
                chkmax(f[i][j][0], f[i - 1][j][0] + 1);
                chkmax(f[i][j][1], f[i - 1][j][1] - 1);
                if(j) chkmax(f[i][j][0], f[i - 1][j - 1][1]);
                if(j) chkmax(f[i][j][1], f[i - 1][j - 1][0]);
            }
            else {
                chkmax(f[i][j][0], f[i - 1][j][1]);
                chkmax(f[i][j][1], f[i - 1][j][0]);
                if(j) chkmax(f[i][j][0], f[i - 1][j - 1][0] + 1);
                if(j) chkmax(f[i][j][1], f[i - 1][j - 1][1] - 1);
            }
        }
    }
    cout << max(f[n][m][0], f[n][m][1]) << endl;
    return 0;
}
