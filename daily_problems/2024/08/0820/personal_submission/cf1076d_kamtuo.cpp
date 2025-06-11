/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-20 15:18 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    struct Node {
        LL u, w, i;
        bool operator < (const Node& now) const {
            return w > now.w;
        };
    };
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ans;
    vector dist(n + 1, 1ll * 0x3f3f3f3f3f3f3f3f);
    vector edge(n + 1, vector<Node> ());
    for (int i = 1; i <= m; i ++) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w, i});
        edge[v].push_back({u, w, i});
    }
    dist[1] = 0;
    priority_queue<Node> pq;
    pq.push({1, 0, -1});
    vector st(n + 1, 0);
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        if (st[now.u]) continue;
        st[now.u] = true;
        if (ans.size() == k) break;
        if (now.i != -1) ans.push_back(now.i);
        for (int i = 0; i < edge[now.u].size(); i ++) {
            int v = edge[now.u][i].u, j = edge[now.u][i].i;
            LL w = edge[now.u][i].w;
            if (dist[v] > dist[now.u] + w) {
                dist[v] = dist[now.u] + w;
                pq.push({v, dist[v], j});
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i ++) cout << ans[i] << ' ';
    return 0;
}

#endif

/*

*/
