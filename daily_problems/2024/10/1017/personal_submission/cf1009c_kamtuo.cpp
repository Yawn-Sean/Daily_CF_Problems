/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-17 18:49 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector x(m + 1, 0), d(m + 1, 0);
    LL bs = 1ll * n * (n - 1) / 2;
    LL now = (n + 1) / 2;
    LL ss = 0;
    for (int i = 1; i <= n; i ++) ss += labs(now - i);
    LL ans = 0;
    for (int i = 1; i <= m; i ++) {
        cin >> x[i] >> d[i];
        if (d[i] >= 0) {
            ans += 1ll * n * x[i] + 1ll * d[i] * bs;
        } else {
            ans += 1ll * n * x[i] + 1ll * d[i] * ss;
        }
    }
    // debug("ans:", ans);
    printf("%.12lf\n", ans * 1.0 / n);
    return 0;
}

#endif

/*

*/
