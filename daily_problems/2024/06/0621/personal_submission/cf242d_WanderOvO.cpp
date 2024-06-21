/*
每选择一个点，可以把这个点以及和这个点直接相连的点的权值 + 1
选一些点去按，使得所有点 u 的权值 != 给定的权值
如果所有 a[u] > 0，则显然不需要按
如果按所有点，则最后每个点的权值 = 度数 + 1
每个点 u 的权值只可能 = a[u] 一次
可否贪心？每轮贪心选择等于的点，按一下，然后更新其他点的信息
更新其他点的信息时，相当于 bfs 扩展了一层
假如权值更新到恰好为 a[u]，则加入集合，否则不加入集合
边数 m <= 1e5，所以度数之和 <= 2e5
*/

int T;
vector<vector<int>> e(N);
vector<int> a(N), d(N, 0), val(N, 0);
bool vis[N];
int n, m;

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        d[u]++;
        d[v]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    queue<int> invalid;
    set<int> press;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            invalid.push(i);
        }
    }
    while (!invalid.empty()) {
        int u = invalid.front();
        invalid.pop();
        if (val[u] > a[u]) continue; 
        vis[u] = true;
        val[u]++;
        press.insert(u);
        for (auto &v : e[u]) {
            if (!vis[v]) {
                val[v]++;
                if (val[v] == a[v]) {
                    invalid.push(v);
                }
            }
        }
    }
    cout << press.size() << "\n";
    for (auto u : press) {
        cout << u << " ";
    }
}          