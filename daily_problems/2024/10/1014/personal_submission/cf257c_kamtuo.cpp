/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-14 19:05 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector x(n, 0.0), y(n, 0.0);
    vector an(n, 0.0);
    for (int i = 0; i < n; i ++) {
        cin >> x[i] >> y[i];
        an[i] = atan2(y[i], x[i]);
    }
    sort(an.begin(), an.end());
    double ans = 0.0;
    for (int i = 1; i < n; i ++) {
        ans = max(ans, an[i] - an[i - 1]);
    }
    double pi = atan2(0, -1);
    cout << std::setprecision(10) << min(2.0 * pi - ans, an[n - 1] - an[0]) / pi * 180.0 << "\n";
    return 0;
}

#endif

/*

*/
