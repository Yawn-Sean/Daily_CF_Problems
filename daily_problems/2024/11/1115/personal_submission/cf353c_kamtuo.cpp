/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-15 14:53 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector a(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i ++) cin >> a[i], sum += a[i];
    reverse(a.begin(), a.end());
    string m;
    cin >> m;
    reverse(m.begin(), m.end());
    int ans = 0, now = 0;
    for (int i = 0; i < n; i ++) {
        if (m[i] == '1') {
            ans = max(ans, sum - a[i] + now);
            now += a[i];
        }
        sum -= a[i];
    }
    ans = max(ans, now);
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
