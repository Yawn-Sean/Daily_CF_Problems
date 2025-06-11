/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-31 17:05 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, h;
    cin >> n >> h;
    vector<int> x(2 * n + 2), s(2 * n + 2);
    x[0] = -1e9;
    x[2 * n + 1] = 2e9;
    for (int i = 1; i <= n; i ++) {
        cin >> x[i * 2 - 1] >> x[i * 2];
    }
    int ans = 0;
    for (int i = n * 2 + 1; i >= 1; i --) {
        if (i % 2) s[i - 1] = x[i] - x[i - 1];
        else s[i - 1] = 0;
    }
    int now = 0;
    for (int i = 2 * n - 1, j = 2 * n - 2; i >= 1; now -= s[i - 1], i -= 2) {
        while (now + s[j] <= h - 1) now += s[j --];
        ans = max(ans, x[i + 1] - x[i] + 1 + x[i] - x[j + 1] + (h - 1) - now);
    }
    cout << ans << endl;
    return 0;
}


/*

*/
