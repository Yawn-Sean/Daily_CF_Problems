/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-04 18:31 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    LL ans = -1;
    if (k > n - 1 + m - 1) cout << -1 << "\n";
    else {
        if (n < m) std::swap(n, m);
        if (k <= n - 1) ans = max(ans, 1ll * n / (k + 1) * m);
        if (k <= m - 1) ans = max(ans, 1ll * m / (k + 1) * n);
        if (k > n - 1) ans = max(ans, (1ll * m / (k - (n - 1) + 1)));
        if (k > m - 1) ans = max(ans, (1ll * n / (k - (m - 1) + 1)));
        cout << ans << "\n";
    }
    return 0;
}

#endif

/*

*/
