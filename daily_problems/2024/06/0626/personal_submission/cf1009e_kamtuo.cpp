/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-06-26 19:57 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

int tp[N], a[N], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    tp[0] = 1;
    for (int i = 1; i <= n; i ++) tp[i] = tp[i - 1] * 2ll % MOD;
    LL ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += 1ll * a[i] * (1ll * tp[n - i] + 1ll * tp[max(n - 1 - i, 0)] * (n - i) % MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}

/*

*/
