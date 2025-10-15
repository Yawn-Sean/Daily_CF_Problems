/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-11-05 18:40 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    if (k > n) {
        cout << "No" << "\n";
        return 0;
    }
    vector st(n + 1, 0);
    vector edge(n + 1, vector<int> ());
    vector cnt(n + 1, 0), dep(n + 1, 0);
    queue<int> q;
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        cnt[u] ++;
        cnt[v] ++;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++) {
        if (cnt[i] == 1) q.push(i), st[i] = 1;
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto v : edge[now]) {
            if (st[v]) {
                if (dep[v] + 1 == dep[now]) continue;
                if (dep[v] != dep[now] + 1) {
                    cout << "No\n";
                    return 0;
                }
                continue;
            }
            if (cnt[v] > 3) {
                st[v] = 1;
                dep[v] = dep[now] + 1;
                q.push(v);
            } else if (cnt[v] == 3) {
                if (dep[now] + 1 != k) {
                    cout << "No\n";
                    return 0;
                }
                st[v] = 1;
                dep[v] = dep[now] + 1;
                q.push(v);
            } else {
                if (st[v] == 0) {
                    cout << "No\n";
                    return 0;
                } else {
                    if (dep[v]) {
                        cout << "No\n";
                        return 0;
                    }
                }
            }
        }
    }
    // debug("dep:", dep);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (dep[i] == k) ans ++;
    } 
    if (ans == 1) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}

#endif

/*

*/
