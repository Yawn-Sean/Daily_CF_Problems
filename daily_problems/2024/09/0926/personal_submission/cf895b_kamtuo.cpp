/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-26 09:08 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, k;
    cin >> n >> x >> k;
    vector a(n, 0ll);
    for (int i = 0; i < n; i ++) cin >> a[i];
    a.push_back(1ll * 1e18);
    sort(a.begin(), a.end());
    LL ans = 0;
    for (int i = 0; i < n; i ++) {
        int now = a[i] / x;
        if (a[i] % x == 0) now --;
        LL l = max(1ll * (now + k) * x, a[i]), r = 1ll * (now + k + 1) * x;
        int sl = lower_bound(a.begin(), a.end(), l) - a.begin();
        int sr = lower_bound(a.begin(), a.end(), r) - a.begin();
        if (sr - 1 < sl) continue;
        ans += sr - 1 - sl + 1;
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
