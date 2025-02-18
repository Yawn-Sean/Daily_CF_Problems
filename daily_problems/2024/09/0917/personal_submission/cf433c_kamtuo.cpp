/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-17 09:42 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << 0 << "\n";
        return 0;
    }
    vector a(m, 0);
    for (int i = 0; i < m; i ++) cin >> a[i];
    LL tot = 0;
    vector to(n + 1, vector<int> ());
    for (int i = 1; i < m; i ++) {
        tot += 1ll * abs(a[i] - a[i - 1]);
        if (a[i] == a[i - 1]) continue;
        to[a[i]].push_back(a[i - 1]);
        to[a[i - 1]].push_back(a[i]);
    }
    LL ans = tot;
    for (int i = 1; i <= n; i ++) {
        if (to[i].size()) {
            sort(to[i].begin(), to[i].end());
            LL res = 0, cnt = 0;
            int now = to[i].size();
            for (int j = 0; j < to[i].size(); j ++) {
                res += 1ll * abs(i - to[i][j]);
                cnt += 1ll * abs(to[i][now / 2] - to[i][j]);
            }
            ans = min(ans, tot - res + cnt);
        }
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
