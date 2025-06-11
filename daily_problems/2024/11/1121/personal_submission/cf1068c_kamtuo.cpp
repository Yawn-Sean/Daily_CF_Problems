/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-21 18:37 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector ans(n + 1, vector<std::pair<int, int>> ());
    vector idy(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        ans[i].push_back({1000 * (i - 1) + 1, 1000 * (i - 1) + 1});
        idy[i] = 1000 * (i - 1) + 1;
    }
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        if (u > v) std::swap(u, v);
        ans[u].push_back({ans[u].back().first, idy[v] - 1});
        ans[v].push_back({ans[v].back().first, idy[v] - 1});
        idy[v] --;
    }
    for (int i = 1; i <= n; i ++) {
        cout << ans[i].size() << "\n";
        for (std::pair<int, int> v : ans[i]) {
            cout << v.first << ' ' << v.second << "\n";
        }
    }
    return 0;
}

#endif

/*

*/
