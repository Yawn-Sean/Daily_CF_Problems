/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-19 19:43 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, l, t;
    cin >> n >> l >> t;
    vector a(n + 1, 0), s(n + 1, 0);
    LL res = 0;
    auto find = [&] (int x) -> int {
        return upper_bound(a.begin(), a.end(), x) - a.begin();
    };
    for (int i = 0; i < n; i ++) cin >> a[i], s[i + 1] = 1;
    a[n] = l + 1;
    for (int i = 1; i <= n; i ++) s[i] += s[i - 1];
    // debug("s:", s);
    for (int i = 0; i < n; i ++) {
        LL now =  2ll * t / l;
        res += now * (s[n] - 1);
        LL tt = (a[i] + 2ll * t) % l;
        int ft = find(tt);
        if (tt >= a[i]) res += (s[ft] - s[i + 1]);
        else res += s[ft] + (s[n] - s[i + 1]);
    }
    printf("%.10lf\n", res / 4.0);
    return 0;
}

#endif

/*

*/
