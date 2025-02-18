/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-27 18:50 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n;
    string s;
    cin >> s >> m;
    vector cnt(n + 1, 0), dp1(n + 1, 0), dp2(n + 1, 0);
    vector a(n + 1, 0), b(n + 1, 0);
    for (int i = 0; i < n; i ++) {
        if (s[i] == '?') cnt[i + 1] = 1;
        cnt[i + 1] += cnt[i];
    }
    for (int i = n - 1; i >= 0; i --) {
        if (s[i] != 'a') b[i] = a[i + 1] + 1;
        if (s[i] != 'b') a[i] = b[i + 1] + 1;
    }
    for (int i = 0; i < n; i ++) {
        if (dp1[i] > dp1[i + 1] || (dp1[i] == dp1[i + 1] && dp2[i] < dp2[i + 1])) {
            dp1[i + 1] = dp1[i];
            dp2[i + 1] = dp2[i];
        }
        if (a[i] >= m) {
            if (dp1[i] + 1 > dp1[i + m] || (dp1[i] + 1 == dp1[i + m] && dp2[i] + cnt[i + m] - cnt[i] < dp2[i + m])) {
                dp1[i + m] = dp1[i] + 1;
                dp2[i + m] = dp2[i] + cnt[i + m] - cnt[i];
            }
        }
    }
    cout << dp2[n] << "\n";
    return 0;
}

#endif

/*

*/
