int n, m;
// 离点i距离为j的个数
int cnt[N][30];
void solve() {
    cin >> n >> m;
    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= m; i ++) {
            int d; cin >> d;
            cnt[i][d] ++;
        }
    }
    LL all = 1;
    for (LL i = 1; i <= n; i ++) all = all * i % mod;
    LL ans = 0;
    for (int i = 1; i <= m; i ++) {
        LL can = 0, c = 1;
        for (int k = n; k >= 1; k --) {
            can += cnt[i][k + 1];
            c = c * can;
            can --;
        }
        c = ((all - c) % mod + mod) % mod;
        ans = (ans + c * inv(all, mod) % mod) % mod;
    }
    cout << ans << endl;
}
