/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-14 17:36 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    const int N = n + 1;
    vector edge(N, vector<int>());
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector maxson(N, 0), fi(N, 0), se(N, 0), st(N, 0);
    int now_cnt = 0;
    std::function<void(int, int)> dfs = [&] (int now, int fa) {
        st[now] = 1;
        for (auto v : edge[now]) {
            if (v == fa) continue;
            dfs(v, now);
            if (fi[v] + 1 > fi[now]) {
                maxson[now] = v;
                fi[now] = fi[v] + 1;
            }
        }
        for (auto v : edge[now]) {
            if (v == fa) continue;
            if (v == maxson[now]) continue;
            se[now] = max(se[now], fi[v] + 1);
        }
        now_cnt = max(now_cnt, fi[now] + se[now]);
    };
    vector<std::pair<int, int>> ans;
    struct Node {
        int u, cnt;
        bool operator < (const Node& now) const {
            return cnt < now.cnt;
        }
    };
    priority_queue<Node> p;
    std::function<void(int, int)> dfs2 = [&] (int now, int fa) {
        if (fi[now] == now_cnt / 2) {
            p.push({now, now_cnt});
            return;
        }
        dfs2(maxson[now], now);
    };
    for (int i = 1; i <= n; i ++) {
        if (!st[i]) {
            now_cnt = 0;
            dfs(i, -1);
            dfs2(i, -1);
        }
    }

    while (!p.empty()) {
        if (p.size() == 1) {
            cout << p.top().cnt << endl;
            break;
        }
        Node now1 = p.top();
        p.pop();
        Node now2 = p.top();
        p.pop();
        ans.push_back({now1.u, now2.u});
        p.push({now1.u, max(now2.cnt, max((now1.cnt + 1) / 2 + ((now2.cnt + 1) / 2) + 1, now1.cnt))});
    }
    for (int i = 0; i < ans.size(); i ++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}

#endif

/*

*/
