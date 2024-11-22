/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-10 09:59 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector p(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i ++) cin >> p[i];
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    int ans = (!(b[n] % 2));
    vector edge(n + 1, vector<int> ());
    vector st(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        edge[i].push_back(p[i]);
    }
    std::function<void (int)> dfs = [&] (int now) {
        st[now] = 1;
        for (auto v : edge[now]) {
            if (st[v]) continue;
            dfs(v);
        }
    };
    int tot = 0;
    for (int i = 1; i <= n; i ++) {
        if (st[i] == 0) {
            dfs(i);
            tot ++;
        }
    }
    if (tot != 1) ans += tot;
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
