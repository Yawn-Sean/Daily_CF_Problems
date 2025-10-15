const int N = 2e3 + 5;

int T, n, a[N][N], xM[10], xm[10], yM[10], ym[10], ans[10];
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n;
        rep(i, 1, n) cin >> s[i];
        rep(i, 1, n) rep(j, 1, n) a[i][j] = s[i][j - 1] - '0';
        rep(d, 0, 9) {
            xM[d] = yM[d] = 0;
            xm[d] = ym[d] = n + 1;
            ans[d] = 0;
        }
        rep(i, 1, n) {
            rep(j, 1, n) {
                int d = a[i][j];
                chkmax(xM[d], i);
                chkmin(xm[d], i);
                chkmax(yM[d], j);
                chkmin(ym[d], j);
            }
        }
        rep(i, 1, n) {
            rep(j, 1, n) {
                int d = a[i][j];
                chkmax(ans[d], max(i - 1, n - i) * max(yM[d] - j, j - ym[d]));
                chkmax(ans[d], max(j - 1, n - j) * max(xM[d] - i, i - xm[d]));
            }
        }
        rep(d, 0, 9) cout << ans[d] << " \n"[d == 9];
    }
    return 0;
}
