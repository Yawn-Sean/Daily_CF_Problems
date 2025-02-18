/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-14 18:23 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, cnt;
    cin >> n >> m >> cnt;
    const int MOD = 998244353;
    vector b(m + 1, 0);
    for (int i = 1; i <= m; i ++) cin >> b[i];
    auto fastpow = [&] (int a, int b) -> int {
        int res = 1;
        while (b) {
            if (b & 1) res = 1ll * a * res % MOD;
            a = 1ll * a * a % MOD;
            b >>= 1;
        }
        return res;
    };
    int ans = fastpow(cnt, n - 2 * b[m]);
    for (int i = 1; i <= m; i ++) {
        ans = 1ll * ans * ((1ll * fastpow(cnt, b[i] - b[i - 1]) * (((fastpow(cnt, b[i] - b[i - 1]) - 1) % MOD + MOD) % MOD) % MOD * fastpow(2, MOD - 2) % MOD + fastpow(cnt, b[i] - b[i  - 1]) % MOD) % MOD) % MOD;
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
