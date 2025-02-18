/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-11 19:02 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(n + 2, 0);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    vector dp1(n + 2, 0ll), dp2(n + 2, 0ll), che(n + 2, 0ll);
    int now = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] > now) dp1[i] = dp1[i - 1];
        else {
            dp1[i] = dp1[i - 1] + now - a[i] + 1;
            now ++;
        }
        now = max(now, a[i]);
        che[i] = now;
    }
    LL ans = 0x3f3f3f3f3f3f3f3f;
    now = 0;
    for (int i = n; i; i --) {
        if (now < a[i]) dp2[i] = dp2[i + 1];
        else {
            dp2[i] = dp2[i + 1] + now - a[i] + 1;
            now ++;
        }
        now = max(now, a[i]);
        if (now <= che[i - 1]) ans = min(ans, 1ll * dp1[i - 1] + dp2[i] + che[i - 1] - now + 1);
        else ans = min(ans, 1ll * dp1[i - 1] + dp2[i]);
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
