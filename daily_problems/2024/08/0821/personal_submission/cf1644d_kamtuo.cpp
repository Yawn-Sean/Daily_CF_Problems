/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-21 10:53 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    const int N = 212345;
    vector x(N + 1, 0), y(N + 1, 0);
    vector stx(N + 1, 0), sty(N + 1, 0);
    for (int _ = 1; _ <= t; _ ++) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        for (int i = 1; i <= q; i ++) {
            int sx, sy;
            cin >> sx >> sy;
            x[i] = sx;
            y[i] = sy;
            stx[x[i]] = 0;
            sty[y[i]] = 0;
        }
        int cnt = 0, cntr = 0, cntl = 0;
        for (int i = q; i >= 1; i --) {
            if ((stx[x[i]] == 0 && cntl != m) || (sty[y[i]] == 0 && cntr != n)) {
                if (stx[x[i]] == 0) cntr ++;
                if (sty[y[i]] == 0) cntl ++;
                cnt ++;
            }
            stx[x[i]] = sty[y[i]] = 1;
        }
        LL ans = 1;
        const int MOD = 998244353;
        for (int i = 1; i <= cnt; i ++) ans = ans * k % MOD;
        cout << ans << endl;
    }
    return 0;
}

#endif

/*

*/
