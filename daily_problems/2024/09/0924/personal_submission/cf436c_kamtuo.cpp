/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-09-24 16:50 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

#ifndef KAMTUO_LEETCODE

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<vector<string>> mp(k, vector<string>(n));
    for (int i = 0; i < k; i ++) {
        for (int j = 0; j < n; j ++) cin >> mp[i][j];
    }
    vector cnt(k, vector (k, 0));
    struct Edge {
        int u, v, wi;
        bool operator < (const Edge &now) const {
            return wi < now.wi;
        };
    };
    vector<Edge> edge;
    for (int i = 0; i < k; i ++) {
        for (int j = 0; j < k; j ++) {
            if (i == j) continue;
            for (int si = 0; si < n; si ++) {
                for (int sj = 0; sj < m; sj ++) {
                    if (mp[i][si][sj] != mp[j][si][sj]) cnt[i][j] ++;
                }
            }
            edge.push_back({i, j, cnt[i][j]});
        }
    }
    vector p(k, 0);
    for (int i = 0; i < k; i ++) p[i] = i;
    std::function<int (int)> find = [&] (int x) -> int {
        if (p[x] - x) p[x] = find(p[x]);
        return p[x];
    };
    sort(edge.begin(), edge.end());
    vector e(k, vector<Edge> ());
    for (int i = 0; i < edge.size(); i ++) {
        int fu = find(edge[i].u), fv = find(edge[i].v), wi = edge[i].wi;
        if (fu - fv) {
            e[edge[i].u].push_back({edge[i].u, edge[i].v, wi});
            e[edge[i].v].push_back({edge[i].v, edge[i].u, wi});
            p[fu] = fv;
        }
    }
    int ans = 0;
    vector<std::pair<int, int>> to;
    vector st(k, 0);
    std::function<void (int, int)> dfs = [&] (int now, int fa) {
        st[now] = 1;
        for (int i = 0; i < e[now].size(); i ++) {
            if (e[now][i].v == fa) continue;
            if (w * e[now][i].wi < n * m) to.push_back({e[now][i].v + 1, now + 1}), ans += e[now][i].wi * w;
            else to.push_back({e[now][i].v + 1, 0}), ans += n * m;
            dfs(e[now][i].v, now);
        }
    };
    for (int i = 0; i < k; i ++) {
        if (st[i] == 0) {
            ans += n * m;
            to.push_back({i + 1, 0});
            dfs(i, -1);
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < to.size(); i ++) {
        cout << to[i].first << ' ' << to[i].second << "\n";
    }
    return 0;
}

#endif

/*

*/
