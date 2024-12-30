/*
n <= 100, m <= 5000
操作顺序完全没关系，只关心每个点到底操作了多少次，奇数还是偶数次，偶数次 = 不操作
所以其实就是看到底操作哪些点 1 次
对于为 0 的边，则其必须恰好有一端操作一下，但是操作哪边呢？
如果有一个点 u 确定操作了，那么其他点是否操作是否已经确定了？
从 u 开始 dfs：
- v 已经被走过了，则应该满足 cnt[u] ^ cnt[v] ^ color(u, v) = 1，否则直接寄了
- v 没被走过，则看是否有 cnt[u] ^ cnt[v] ^ color(u, v) = 1，没有则必须对 v 操作
u 点操作次数是 cnt[u]，则 cnt[u] ^ cnt[v] ^ color(u, v) = 1 才行
图可能不连通，所以每个连通块都得做一遍
对于每个连通块，选一个代表点 u，把操作 u 和不操作 u 都算一次，就可以了
*/

struct Edge {
    int v, w;
};

int n, m;
vector<vector<Edge>> e(N);
bool vis[N], confirm[N];
int cnt[N];
bool ok = true;

void dfs(int u) {
    vis[u] = true;
    for (auto edge : e[u]) {
        int v = edge.v, w = edge.w;
        if (vis[v]) {
            if ((cnt[u] ^ cnt[v] ^ w) != 1) {
                ok = false;
                return;
            }
        } else {
            if ((cnt[u] ^ cnt[v] ^ w) != 1) {
                cnt[v]++;
            }
            dfs(v);
        }
    } 
}

void get_nodes(int u, vector<int> &nodes) {
    nodes.push_back(u);
    vis[u] = true;
    confirm[u] = true;
    for (auto edge : e[u]) {
        int v = edge.v;
        if (!vis[v]) {
            get_nodes(v, nodes); 
        }
    }
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }

    memset(confirm, 0, sizeof confirm);
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!confirm[i]) {
            vector<int> nodes;
            memset(vis, 0, sizeof vis);
            get_nodes(i, nodes);
            memset(vis, 0, sizeof vis);
            memset(cnt, 0, sizeof cnt);
            ok = true;
            dfs(i);
            if (!ok) {
                memset(vis, 0, sizeof vis);
                memset(cnt, 0, sizeof cnt);
                cnt[i] = 1;
                ok = true;
                dfs(i);
                if (!ok) {
                    cout << "Impossible\n";
                    return;
                } else {
                    for (auto v : nodes) {
                        if (cnt[v] % 2 != 0) {
                            res.push_back(v);
                        }
                    }
                }
            } else {
                for (auto v : nodes) {
                    if (cnt[v] % 2 != 0) {
                        res.push_back(v);
                    }
                }
            }
        }
    }
    cout << res.size() << "\n";
    for (auto v : res) {
        cout << v << " ";
    }
}
