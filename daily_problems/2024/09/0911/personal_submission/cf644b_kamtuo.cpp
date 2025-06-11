/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-11 14:39 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, b;
    cin >> n >> b;
    vector t(n + 1, 0), d(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> t[i] >> d[i];
    }
    LL now = 0, cnt = 1;
    for (int i = 1, j = 1; i <= n; i ++) {
        if (t[i] == -1) {
            cout << "-1" << ' ';
            continue;
        }
        cnt --;
        now = max(1ll * t[i], now) + d[i];
        cout << now << ' ';
        while (j <= n && t[j] < now) {
            if (cnt > b) t[j] = -1;
            else cnt ++;
            j ++;
        }

    }
    return 0;
}

#endif

/*

*/
