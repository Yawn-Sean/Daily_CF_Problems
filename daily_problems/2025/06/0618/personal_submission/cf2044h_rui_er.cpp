const ll N = 2e3 + 5;

ll T, n, q, a[N][N], S[N][N], Si[N][N], Sj[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n >> q;
        rep(i, 1, n) rep(j, 1, n) cin >> a[i][j];
        rep(i, 1, n) {
            rep(j, 1, n) {
                S[i][j] = a[i][j];
                Si[i][j] = a[i][j] * i;
                Sj[i][j] = a[i][j] * j;
                S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
                Si[i][j] += Si[i - 1][j] + Si[i][j - 1] - Si[i - 1][j - 1];
                Sj[i][j] += Sj[i - 1][j] + Sj[i][j - 1] - Sj[i - 1][j - 1];
            }
        }
        while(q--) {
            ll u, l, d, r;
            cin >> u >> l >> d >> r;
            ll s = S[d][r] - S[u - 1][r] - S[d][l - 1] + S[u - 1][l - 1];
            ll si = Si[d][r] - Si[u - 1][r] - Si[d][l - 1] + Si[u - 1][l - 1];
            ll sj = Sj[d][r] - Sj[u - 1][r] - Sj[d][l - 1] + Sj[u - 1][l - 1];
            ll ans = (r - l + 1) * si + sj - (u * (r - l + 1) + l - 1) * s;
            cout << ans << " \n"[!q];
        }
    }
    return 0;
}
