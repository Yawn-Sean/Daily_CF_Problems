/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-20 09:06 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector edge(n + 1, vector<int> ());
    vector cnt(n + 1, 0);
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        cnt[u] ++;
        cnt[v] ++;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    LL ans = 0;
    vector in(n + 1, 1), de(n + 1, 1);
    for (int i = 1; i <= n; i ++) {
        for (int v : edge[i]) {
            if (v < i) de[i] = max(de[i], de[v] + 1);
        }
    }
    for (int i = 1; i <= n; i ++) {
        ans = max(1ll * de[i] * cnt[i], ans);
    }
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
