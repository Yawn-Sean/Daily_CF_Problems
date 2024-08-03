/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-08-02 16:31 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#if !KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, idx = 1;
    cin >> n >> m;
    vector ans(m, -1), ne(m << 2, 0), d(m << 2, 0), e(m << 2, 0), c(m << 2, 0), h(n, 0), tot(n, 0), ad(n, 0);
    vector edge(m, 0);
    std::function <void(int, int, int, int)> add = [&] (int u, int v, int w, int i) {
        ne[idx] = h[u];
        d[idx] = v;
        c[idx] = w;
        e[idx] = i;
        h[u] = idx ++;
    };
    for (int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        u --, v --;
        tot[u] += w;
        tot[v] += w;
        add(u, v, w, i);
        add(v, u, w, i);
        edge[i] = u;
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = h[now]; i; i = ne[i]) {
            if (ans[e[i]] != -1) continue;
            ans[e[i]] = 1 ^ (edge[e[i]] == now);
            tot[d[i]] -= c[i];
            ad[d[i]] += c[i];
            if (tot[d[i]] == ad[d[i]] && d[i] != n - 1) {
                q.push(d[i]);
            }
        }
    }
    for (int i = 0; i < m; i ++) {
        cout << ans[i] << "\n";
    }
    return 0;
}

#endif

/*

*/
