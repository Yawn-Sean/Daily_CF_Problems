/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-23 19:37 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector edge(n, vector<int> ());
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        edge[u].push_back(v);
    }
    vector st(n, 0);
    std::function<void (int)> dfs = [&] (int now) {
        if (st[now]) return;
        st[now] = 1;
        for (auto v : edge[now]) {
            dfs(v);
        }
        cout << now + 1 << ' ';
    };
    for (int i = 0; i < n; i ++) {
        dfs(i);
    }
    return 0;
}

#endif

/*

*/
