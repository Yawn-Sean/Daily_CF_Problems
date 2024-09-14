/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-12 09:55 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    const int idx = 1000;
    vector dp(m + 1, vector (2123, 0));
    vector a(m + 1, vector (n, 0));
    for (int i = 1; i <= m; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];
        }
    }
    vector<int> ans(m + 1, 0);
    for (int i = 0; i < n - 1; i ++) {
        vector<std::pair<int, int>> nums;
        vector<int> res;
        int now = 0, cnt = 0;
        for (int j = 1; j <= m; j ++) {
            if (a[j][i] - a[j][n - 1] >= 0) now += a[j][i] - a[j][n - 1], cnt ++;
            else nums.push_back({a[j][n - 1] - a[j][i], j});
        }
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size(); j ++) {
            now -= nums[j].first;
            if (now < 0) res.push_back(nums[j].second);
        }
        if (ans.size() > res.size()) {
            ans = res;
        }
    }
    cout << ans.size() << "\n";
    for (auto v : ans) cout << v << ' ';
    return 0;
}

#endif

/*

*/
