/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-20 19:23 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL h, n;
    cin >> h >> n;
    int pre = n % 2;
    int now = 1;
    LL ans = 0;
    // h ++;
    while (h --) {
        ans ++;
        n = (n + 1) / 2;
        if (h == 0) break;
        if (n % 2 == pre) {
            ans += (1ll << (1ll * now)) - 1;
        }
        now ++;
        pre = n % 2;
    }
    if (pre == 0) ans += (1ll << (1ll * now)) - 1;
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
