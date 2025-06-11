/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-22 19:07 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL m;
    cin >> m;
    LL l = 1, r = 1e18;
    while (l < r) {
        LL mid = l + r >> 1;
        LL cnt = 0;
        for (int i = 2; i <= 1000000; i ++) {
            cnt += mid / (1ll * i * i * i);
        }
        if (cnt >= m) r = mid;
        else l = mid + 1;
    }
    LL cnt = 0;
    for (int i = 2; i <= 1000000; i ++) {
        cnt += r / (1ll * i * i * i);
    }
    if (cnt != m) cout << -1 << endl;
    else cout << r << endl;
    return 0;
}

#endif

/*

*/
