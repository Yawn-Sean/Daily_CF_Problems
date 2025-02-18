/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-06 11:50 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n;
    cin >> n;
    LL now = 1;
    LL cnt = 0;
    for (int i = 1; i <= 12; i ++) {
        if (cnt + 9 * now * i >= n) {
            n -= cnt;
            LL ans = n / i + (n % i != 0) + now - 1;
            n -= i * (n / i + (n % i != 0) - 1);
            string s = std::to_string(ans);
            cout << s[n - 1] << endl;
            break;
        }
        cnt += 9 * now * i;
        now *= 10;
    }
    return 0;
}

#endif

/*

*/
