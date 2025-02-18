/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-21 19:49 */
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
    vector chosen(n +  1, 0), cnt(n + 1, 0);
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        cnt[v] ++;
    }
    vector a(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        chosen[a[i]] = a[i];
    }
    vector st(n + 1, 0), dep(n + 1, 0);
    std::function<void (int, int)> dfs = [&] (int now, int fa) -> void {
        if (chosen[now] == 0) chosen[now] = chosen[fa]; 
        dep[now] = dep[fa] + 1;
        for (int i = 0; i < edge[now].size(); i ++) {
            dfs(edge[now][i], now);
        }
    }; 
    for (int i = 1; i <= n; i ++) {
        if (cnt[i] == 0) dfs(i, 0);
    }
    bool ok = true;
    for (int i = 1; i <= n; i ++) {
        if (chosen[i] != a[i]) ok = false;
    }
    if (ok) {
        // debug("a:", a);
        vector<int> ans;
        for (int i = 1; i <= n; i ++) if (chosen[i] == i) ans.push_back(i);
        sort(ans.begin(), ans.end(), [&] (int a, int b) {return dep[a] > dep[b];});
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i ++) cout << ans[i] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

#endif

/*

*/
