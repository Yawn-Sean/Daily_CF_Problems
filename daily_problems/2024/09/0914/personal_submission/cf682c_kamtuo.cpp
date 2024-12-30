/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-14 12:44 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    const int N = n + 1;
    vector a(N, 0);
    struct EDGE { 
        int v, c;
    };
    vector edge(N, vector<EDGE> ());
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i ++) {
        int v, c;
        cin >> v >> c;
        edge[v].push_back({i + 1, c});
        edge[i + 1].push_back({v, c});
    }
    vector sz(N, 0);
    std::function<void (int, int)> dfs = [&] (int now, int fa) {
        sz[now] = 1;
        for (auto v : edge[now]) {
            if (fa == v.v) continue;
            dfs(v.v, now);
            sz[now] += sz[v.v];
        }
    };
    vector dist(N, 0ll), mind(N, 0ll);
    int ans = 0;
    std::function<void (int, int)> cal = [&] (int now, int fa) {
        if (dist[now] - mind[now] > a[now]) {
            ans += sz[now];
            return;
        }
        for (auto v : edge[now]) {
            if (v.v == fa) continue;
            dist[v.v] = dist[now] + v.c;
            mind[v.v] = min(dist[now], mind[now]);
            cal(v.v, now);
        }
    };
    dfs(1, -1);
    cal(1, -1);
    cout << ans << "\n";
    return 0;
}

#endif

/*

*/
