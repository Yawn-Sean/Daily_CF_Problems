/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-03-05 14:10                         */
/* Software : Visual Studio Code                            */
/*                                                          */
/*  ██╗  ██╗ █████╗ ███╗   ███╗████████╗██╗   ██╗ ██████╗   */
/*  ██║ ██╔╝██╔══██╗████╗ ████║╚══██╔══╝██║   ██║██╔═══██╗  */
/*  █████╔╝ ███████║██╔████╔██║   ██║   ██║   ██║██║   ██║  */
/*  ██╔═██╗ ██╔══██║██║╚██╔╝██║   ██║   ██║   ██║██║   ██║  */
/*  ██║  ██╗██║  ██║██║ ╚═╝ ██║   ██║   ╚██████╔╝╚██████╔╝  */
/*  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝   ╚═╝    ╚═════╝  ╚═════╝   */
/*----------------------------------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k, s, t;
    cin >> n >> m >> k;
    vector edge(n + 1, vector<int> ());
    vector pos(n + 1, 0), st(n + 1, 0), ro(n + 1, 0), dis(n + 1, 0x3f3f3f3f);
    for (int i = 1; i <= k; i ++) {
        int x;
        cin >> x;
        pos[x] = 1;
    }
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    cin >> s >> t;
    struct Node {
        int now;
        int dis;
    };
    queue<Node> q;
    pos[t] = 1;
    for (int i = 1; i <= n; i ++) {
        if (pos[i]) q.push({i, 0}), ro[i] = i, st[i] = 1;
    }
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        dis[now.now] = now.dis;
        for (int i = 0; i < edge[now.now].size(); i ++) {
            if (st[edge[now.now][i]]) continue;
            st[edge[now.now][i]] = 1;
            ro[edge[now.now][i]] = ro[now.now];
            q.push({edge[now.now][i], now.dis + 1});
        }
    }
    // debug("dis:", dis);
    // debug("ro:", ro);
    int l = 1, r = n;
    auto check = [&] (int mid) -> bool {
        for (int i = 1; i <= n; i ++) st[i] = 0;
        st[s] = 1;
        q.push({s, 0});
        while (!q.empty()) {
            Node now = q.front();
            q.pop();
            for (int i = 0; i < edge[now.now].size(); i ++) {
                if (st[edge[now.now][i]]) continue;
                if (ro[now.now] == ro[edge[now.now][i]]) {
                    if (dis[now.now] + dis[edge[now.now][i]] > mid) continue;
                } else {
                    if (dis[now.now] + dis[edge[now.now][i]] + 1 > mid) continue;
                }
                st[edge[now.now][i]] = 1;
                q.push({edge[now.now][i], 0});
            }
        }
        return st[t];
    };
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    // debug("check(3):", check(3));
    if (check(r)) {
        cout << r << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}

#endif

/*

*/
