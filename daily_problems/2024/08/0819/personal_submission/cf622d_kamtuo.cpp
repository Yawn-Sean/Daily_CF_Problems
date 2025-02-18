/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-20 14:56 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector ans(2 * n + 1, n);
    for (int i = 1, j = 1; j <= n; i ++, j += 2) {
        ans[i] = ans[n - i + 1] = j;
    }
    for (int i = n + 1, j = 2; j <= n; i ++, j += 2) {
        ans[i] = ans[2 * n - 1 - (i - n) + 1] = j;
    }
    for (int i = 1; i <= 2 * n; i ++) cout << ans[i] << ' ';
    return 0;
}

#endif

/*

*/
