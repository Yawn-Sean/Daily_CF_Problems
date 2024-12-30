/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-07 11:54 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, x;
    cin >> n >> k >> x;
    LL res = 1;
    for (int i = 1; i <= k; i ++) {
        res *= x; 
    }
    vector a(n + 1, 0), pre(n + 2, 0), nex(n + 2, 0);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        pre[i] = (pre[i - 1] | a[i]);
    }
    for (int i = n; i; i --) {
        nex[i] = (nex[i + 1] | a[i]);
    }
    LL ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = max(ans, (a[i] * 1ll * res) | nex[i + 1] | pre[i - 1]);
    }
    cout << ans << endl;
    return 0;
}

#endif

/*

*/
