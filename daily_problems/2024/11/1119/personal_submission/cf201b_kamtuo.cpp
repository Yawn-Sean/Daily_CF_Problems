/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-19 15:32 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector a(n + 1, vector (m + 1, 0));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    vector cntl(m + 1, 0), cntr(n + 1, 0);
    vector resl(m + 1, 0ll), resr(n + 1, 0ll);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cntl[j] += a[i][j];
            cntr[i] += a[i][j];
        }
    }
    for (int i = 0; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            int now;
            if (j > i) now = (j - i - 1) * 4 + 2;
            else now = (i - j) * 4 + 2; 
            resr[i] += 1ll * cntr[j] * now * now;
        }
    }
    for (int i = 0; i <= m; i ++) {
        for (int j = 1; j <= m; j ++) {
            int now;
            if (j > i) now = (j - i - 1) * 4 + 2;
            else now = (i - j) * 4 + 2; 
            resl[i] += 1ll * cntl[j] * now * now;
        }
    }
    LL ans = 0x3f3f3f3f3f3f3f3f;
    int x = 0, y = 0;
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) {
            if (ans > resl[j] + resr[i]) {
                ans = resl[j] + resr[i];
                x = i, y = j;
            }
        }
    }
    cout << ans << "\n";
    cout << x << ' ' << y << "\n";
    return 0;
}

#endif

/*

*/
