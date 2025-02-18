/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-13 17:12 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, l, r;
    cin >> t >> l >> r;
    const int MOD = 1e9 + 7, N = r + 1;
    vector p(N, 0), st(N, 0), minp(N, 0);
    int cnt = 0;
    auto cal_pri = [&] () {
        for (int i = 2; i <= r; i ++) {
            if (st[i] == 0) {
                p[cnt ++] = i;
                minp[i] = i;
            }
            for (int j = 0; 1ll * i * p[j] <= r; j ++) {
                st[i * p[j]] = 1;
                minp[i * p[j]] = p[j];
                if (i % p[j] == 0) break;
            }
        }
    };
    cal_pri();
    LL ans = 0;
    vector f(N, 0);
    for (int i = 2; i <= r; i ++) {
        f[i] = (1ll * i / minp[i] * (1ll * (minp[i] - 1) * minp[i] / 2) + f[i / minp[i]]) % MOD;
    }
    vector tp(N, 0);
    tp[0] = 1;
    for (int i = l; i <= r; i ++) {
        tp[i - l + 1] = tp[i - l] * 1ll * t % MOD;
        ans += 1ll * f[i] * tp[i - l] % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}

#endif

/*

*/
