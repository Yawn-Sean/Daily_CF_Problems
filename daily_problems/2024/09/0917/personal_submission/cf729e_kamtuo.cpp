/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-17 14:09 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s, now = 0;
    cin >> n >> s;
    vector a(n, 0), cnt(n, 0);
    for (int i = 0; i < n; i ++) cin >> a[i], cnt[a[i]] ++;
    int res = 0;
    for (int i = 0; i < n; i ++) {
        if (i == s - 1 && a[i]) res ++;
        if (i != s - 1 && a[i] == 0) now ++;
    }
    int tot = n;
    cnt[0] += res;
    cnt[a[s - 1]] -= res;
    tot -= cnt[0];
    int ans = n, to = 0;
    for (int i = 1; i < n; i ++) {
        tot -= cnt[i];
        if (cnt[i] == 0) to ++;
        ans = min(ans, now + tot + max(to - tot - now, 0));
    }
    if (n == 1) {
        cout << res << "\n";
    } else {
        cout << ans + res << "\n";
    }
    return 0;
}

#endif

/*

*/
