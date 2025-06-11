/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-21 19:12 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    vector cnt(n + 2, 0);
    vector<int> to;
    to.push_back(0);
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'G') cnt[i + 1] = 1;
        else to.push_back(i + 1);
    }
    for (int i = 1; i <= n + 1; i ++) cnt[i] += cnt[i - 1];
    to.push_back(n + 1);
    if (to.size() == 2) {
        cout << cnt[n] << "\n";
        return 0;
    }
    int ans = 0;
    for (int i = 1; i < to.size() - 1; i ++) {
        bool ok = true;
        if (to[i] - 2 >= 0 && s[to[i] - 2] == 'S') ok = false;
        if (to[i] < n && s[to[i]] == 'S') ok = false;
        ans = max(cnt[to[i + 1]] - cnt[to[i - 1]] + 1, ans);
    }
    cout << min(ans, cnt[n]) << "\n";
    return 0;

}

#endif

/*

*/
