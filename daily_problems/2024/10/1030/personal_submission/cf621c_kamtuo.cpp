/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-30 13:53 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, p;
    cin >> n >> p;
    vector l(n, 0), r(n, 0);
    vector h(n, 0.0);
    for (int i = 0; i < n; i ++) {
        cin >> l[i] >> r[i];
        h[i] = (r[i] / p - l[i] / p + (l[i] % p == 0)) / (double)(r[i] - l[i] + 1);
    }
    auto mod = [&] (int x) -> int {
        return (x % n + n) % n;
    };
    double ans = 0;
    // debug("h:", h);
    for (int i = 0; i < n; i ++) {
        ans += 1000.0 * (1 - (1 - h[mod(i - 1)]) * (1 - h[i]));
        ans += 1000.0 * (1 - (1 - h[mod(i + 1)]) * (1 - h[i]));
        // ans += 1000.0 * (h[mod(i - 1)] + h[mod(i + 1)]);
    }
    printf("%.10lf\n", ans);
    return 0;
}

#endif

/*

*/
