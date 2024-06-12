
/*
有向图，a -> b -> c -> d 最短路最长，n = 3000，5s
感觉可以 BFS 预处理全源最短路，以及反图上的全源最短路
然后枚举 b 和 c，在反图上找 b 出发的最远距离，正图上找 c 出发的最短距离
b 不能再走到 c，c 不能再走到 b，b 和 c 也不能走到同一个点
所以其实需要维护前三大的距离以及对应的点
*/

int T;
int n, m;
int d[N][N], rd[N][N];
bool vis[N];
vector<vector<int>> e(N), re(N);
vector<vector<PII>> sorted_d(N), sorted_rd(N);

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        re[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        bfs(i, e, d[i]);
        bfs(i, re, rd[i]);
    }

    // 感谢烟花哥哥的代码
    auto push = [&](vector<PII> &it, int d, int i) {
        it.emplace_back(d, i);
        if (it.size() == 4) {
            nth_element(it.begin(), it.begin() + 3, it.end(), greater<PII>());
            it.erase(it.begin() + 3, it.end());
        }
    };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || d[i][j] == INF) continue;
            push(sorted_d[i], d[i][j], j);
        }
        for (int j = 1; j <= n; j++) {
            if (i == j || rd[i][j] == INF) continue;
            push(sorted_rd[i], rd[i][j], j);
        }
    }
    int res = 0;
    vector<int> nodes;
    for (int b = 1; b <= n; b++) {
        for (int c = 1; c <= n; c++) {
            if (b != c && d[b][c] != INF) {
                int ans = d[b][c];
                int len1 = min(3, (int)sorted_rd[b].size());
                int len2 = min(3, (int)sorted_d[c].size());
                for (int i = 0; i < len1; i++) {
                    for (int j = 0; j < len2; j++) {
                        PII u1 = sorted_rd[b][i], u2 = sorted_d[c][j];
                        int a = u1.y, d = u2.y;
                        if (a != b && a != c && d != b && d != c && a != d) {
                            if (res < ans + u1.x + u2.x) {
                                nodes.clear();
                                nodes.pb(a);
                                nodes.pb(b);
                                nodes.pb(c);
                                nodes.pb(d);
                            }
                            res = max(res, ans + u1.x + u2.x);
                        }
                    }
                }
            }
        }
    }
    for (auto node : nodes) {
        cout << node << " ";
    }
}              