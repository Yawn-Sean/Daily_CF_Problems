/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-11 08:24 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector a(n + 1, vector (m + 1, 0x3f3f3f3f));
    for (int i = 1; i <= q; i ++) {
        int x, y, t;
        cin >> x >> y >> t;
        a[x][y] = t;
    }
    int hh = 0, tt = -1;
    vector idx(max(n + 1, m + 1), 0), val(max(n + 1, m + 1), 0);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            while (hh <= tt && (val[tt] <= a[i][j])) tt --;
            val[++ tt] = a[i][j];
            idx[tt] = j;
            while (hh <= tt && (idx[hh] <= j - k)) hh ++;
            a[i][j] = val[hh];
        }
        hh = 0, tt = -1;
    }
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            while (hh <= tt && (val[tt] <= a[j][i])) tt --;
            val[++ tt] = a[j][i];
            idx[tt] = j;
            while (hh <= tt && (idx[hh] <= j - k)) hh ++;
            a[j][i] = val[hh];
        }
        hh = 0, tt = -1;
    }
    int ans = 0x3f3f3f3f;
    for (int i = k; i <= n; i ++) {
        for (int j = k; j <= m; j ++) {
            ans = min(ans, a[i][j]);
        }
    }
    if (ans == 0x3f3f3f3f) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}

#endif

/*

*/
