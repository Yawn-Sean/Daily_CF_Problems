/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-10-25 10:17 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    struct Node {
        int i;
        int v;
    };
    vector edge(n + 1, vector<Node> ());
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back({i, v});
        edge[v].push_back({i, u});
    }
    vector dep(n + 1, 0);
    queue<int> q;
    q.push(1);
    vector st(n + 1, 0);
    st[1] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto v : edge[now]) {
            if (st[v.v]) continue;
            st[v.v] = 1;
            dep[v.v] = dep[now] + 1;
            q.push(v.v);
        }
    }
    vector to(n + 1, vector<int> ());
    to[1].push_back(0);
    for (int i = 1; i <= n; i ++) {
        // debug("i:", i);
        for (auto v : edge[i]) {
            if (dep[v.v] == dep[i] + 1) {
                // debug("1");
                to[v.v].push_back(v.i);
            }
        }
    }
    LL tot = 1;
    // for (int i = 1; i <= n; i ++) {
    //     debug("i:", i, "to:", to[i]);
    // }
    vector used(m + 1, 0);
    std::function<void (int)> dfs = [&] (int now) {
        if (k == 0) return;
        if (now == n + 1) {
            for (int i = 1; i <= m; i ++) {
                if (used[i]) cout << 1;
                else cout << 0;
            }
            cout << "\n";
            k --;
            return;
        }
        for (int i = 0; i < to[now].size(); i ++) {
            used[to[now][i]] = 1;
            dfs(now + 1);
            used[to[now][i]] = 0;
        }
    };
    for (int i = 1; i <= n; i ++) {
        tot *= to[i].size();
        if (tot >= k) {
            cout << k << "\n";
            dfs(1);
            return 0;
        }
    }
    cout << tot << "\n";
    dfs(1);
    return 0;
}

#endif

/*

*/
