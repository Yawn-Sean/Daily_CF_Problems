/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-12 11:39 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector to(n + 1, vector<int>());
    for (int i = 1; i <= m; i ++) {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    for (int i = 1; i <= n; i ++) {
        if (to[i].size() < n - 1) {
            cout << "YES" << endl;
            vector st(n + 1, 0);
            st[i] = 1;
            for (int j = 0; j < to[i].size(); j ++) st[to[i][j]] = 1;
            int x = i, y;
            for (int j = 1; j <= n; j ++) if (st[j] == 0) {
                y = j;
            }
            vector ans(n + 1, 0);
            int cnt = 3;
            for (int j = 1; j <= n; j ++) {
                if (j == x || j == y) continue;
                ans[j] = cnt ++;
            }
            ans[x] = 1;
            ans[y] = 2;
            for (int j = 1; j <= n; j ++) cout << ans[j] << " \n"[j == n];
            ans[y] = 1;
            for (int j = 1; j <= n; j ++) cout << ans[j] << " \n"[j == n];
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

#endif

/*

*/
