/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-15 16:38 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, l, v1, v2;
    cin >> n >> l >> v2 >> v1;
    vector a(2 * n + 1, 0ll);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    a[n + 1] = a[1] + (2 * l);
    for (int i = n + 2; i <= 2 * n; i ++) {
        a[i] = a[i - 1] + (a[i - n] - a[i - n - 1]);
    }
    // for (int i = 1; i <= n * 2; i ++) {
    //     cout << a[i] << "\n";
    // }
    for (int i = 1; i <= 2 * n; i ++) a[i] = (1ll * v1 + v2) * a[i];
    vector cnt(n + 1, 0ll);
    for (int i = n; i < 2 * n; i ++) {
        int now = i;
        if (i - 1 != 0) now = lower_bound(a.begin() + 1, a.begin() + i, a[i] - 1ll * v1 * l) - a.begin();
        LL pre = (a[i] - 1ll * v1 * l);
        int sum = i - now + 1;
        while (now <= i && a[now] + 1ll * v1 * l < a[i + 1]) {
            cnt[sum] += a[now] - pre;
            pre = a[now];
            now ++;
            sum --;
        }
        cnt[sum] += a[i + 1] - 1ll * v1 * l - pre;
    }
    for (int i = 0; i <= n; i ++) {
        printf("%.15lf\n", cnt[i] / (1.0 * (v1 + v2)) / (2.0 * l));
    }
    return 0;
}

#endif

/*

*/
