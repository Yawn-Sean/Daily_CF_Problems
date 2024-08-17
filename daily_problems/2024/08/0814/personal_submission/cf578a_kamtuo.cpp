/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-14 11:59 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double x, y;
    cin >> x >> y;
    double b = y + x;
    bool ok = true;
    double ans;
    if (b / 2.0 < y) {
        ok = false;
    } else {
        int l = 1, r = 1000000000;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (b / ((double)mid * 2) >= y) l = mid;
            else r = mid - 1;
        }
        if (b / ((double)l * 2) >= y) ans = b / ((double)l * 2);
        else ans = b / 2.0;
    }
    if (ok) printf("%.12lf", ans);
    else cout << -1 << endl;
    return 0;
}

#endif

/*

*/
