/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-24 18:36 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    const int N = 211111;
    vector a(n, 0);
    vector tr(N, 0), cnt(N, 0);
    auto lowbit = [&] (int x) -> int {
        return x & -x;
    };
    auto add = [&] (int x, int v) {
        for (int i = x; i < N; i += lowbit(i)) tr[i] += v;
    };
    auto query = [&] (int x) -> int {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    };
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        cnt[a[i]] = 1;
        add(a[i], 1);
    }
    LL ans = 0;
    for (int i = 1; i <= 200000; i ++) {
        LL res = 0;
        if (cnt[i] == 0) continue;
        for (int j = 1; 1ll * j * i <= 200000; j ++) {
            res += 1ll * j * i * (query(min(1ll * (j + 1) * i - 1, 200000ll)) - query(j * i - 1));
        }
        ans = max(ans, res);
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
