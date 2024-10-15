/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-05 10:04 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    const int N = 123456;
    vector cnt(N, 0), st(N, 0);
    vector a(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    for (int i = 0; i <= 100000; i ++) {
        int now = i;
        int s = 0;
        while (now) {
            s += now % 2;
            now >>= 1;
        }
        if (s == k) st[i] = 1;
    }
    LL ans = 0;
    for (int i = 0; i <= 10000; i ++) {
        for (int j = 0; j < i; j ++) {
            if (st[i ^ j]) ans += 1ll * cnt[i] * cnt[j];
        }
        if (st[0]) ans += 1ll * cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
