/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-25 19:55 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector edge(n, vector<int> ());
    vector cnt(n, 0);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        cnt[u] ++;
        cnt[v] ++;
        if (cnt[u] > 4 || cnt[v] > 4) {
            cout << "NO" << "\n";
            return 0;
        }
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    struct Node {
        int u;
        LL x, y;
        int pre;
        LL now;
    };
    queue<Node> q;
    vector st(n, 0);
    st[0] = 1;
    q.push({0, 0, 0, -1, 1000000000000ll});
    vector idx = {0, 0, 1, -1}, idy = {1, -1, 0, 0};
    vector<std::pair<LL, LL>> ans(n);
    ans[0] = {0, 0};
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (now.pre == 0) now.pre = 1;
        else if (now.pre == 1) now.pre = 0;
        else if (now.pre == 2) now.pre = 3;
        else now.pre = 2;
        int k = (now.pre + 1) % 4;
        for (int i = 0; i < edge[now.u].size(); i ++) {
            if (st[edge[now.u][i]]) continue;
            st[edge[now.u][i]] = 1;
            q.push({edge[now.u][i], now.x + idx[k] * now.now, now.y + idy[k] * now.now, k, now.now / 2});
            ans[edge[now.u][i]] = {now.x + idx[k] * now.now, now.y + idy[k] * now.now};
            k ++;
            k %= 4;
        }
    }
    cout << "YES" << "\n";
    for (int i = 0; i < n; i ++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}

#endif

/*

*/
