/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-02 11:12 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

LL C(int n, int m) {
    LL res = 1;
    for (int i = n, j = 1; j <= m; i --, j ++) {
        res = res * 1ll * i / j;
    }
    return res;
}

#if !KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    vector cnt = {0, 1, 2, 9};
    cin >> n >> k;
    LL ans = 0;
    for (int i = 2; i <= k; i ++) {
        ans += 1ll * C(n, i) * cnt[i - 1];
    }
    cout << ans + 1 << endl;
    return 0;
}

#endif

/*

*/
