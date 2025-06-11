/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-03 10:54 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#if !KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(n + 1, 0), ans(n, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int to = n - 1;
    for (int k = n - 2; 1ll * k * k + 1 >= n; k --) {
        to = k;
    }
    debug("to:", to);
    vector cnt(to + 1, vector(n + 1, 0));
    for (int i = 1; i <= to; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (a[j] < a[i]) cnt[i][j] = 1; 
            cnt[i][j] += cnt[i][j - 1];
        }
    }
    // debug(to);
    for (int i = to; i < n; i ++) {
        for (int j = 1; j <= to; j ++) {
            int l = i * j + 2 - i, r = min(n, i * j + 1);
            if (l > n) break;
            debug("l:", l, "r:", r);
            debug("cnt1:", cnt[j][r], "cnt2:", cnt[j][l - 1]);
            ans[i] += cnt[j][r] - cnt[j][l - 1];
            debug("ans[i]:", ans[i]);
        }
    }
    for (int i = 1; i < to; i ++) {
        for (int j = 1; j <= n; j ++) {
            for (int k = i * j + 2 - i; k <= i * j + 1 && k <= n; k ++) {
                if (a[k] < a[j]) ans[i] ++;
            }
        }
    }
    // debug("to:", to);
    for (int i = 1; i < n; i ++) cout << ans[i] << ' ';
    return 0;
}

#endif

/*

*/
