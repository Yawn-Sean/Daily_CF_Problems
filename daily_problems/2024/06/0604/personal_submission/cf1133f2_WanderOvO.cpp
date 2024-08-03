/*
什么时候不存在？
- 如果 D 大于 1 本身的度，则肯定无解
- 如果 D 太小，导致某个点 u 没能直接连上，而 u 又无法通过其他连上的点 v 连到，则无解
我们需要关注删除 1 之后，哪些点还是在一个连通块里面的
1 需要和每个连通块中至少一个点连一条边
然后以这些点为起点做 dfs，把剩下的点找出来
*/

int T;
int n, m, D, fa[N];
vector<int> e[N];
bool vis[N];

void solve1() {
    cin >> n >> m >> D;
    int d = 0;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].pb(b);
        e[b].pb(a);
        if (a == 1 || b == 1) {
            d++;
        }
        if (a != 1 && b != 1) {
            merge(a, b);
        }
    }
    if (d < D) {
        cout << "NO\n";
        return;
    }

    int block_cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (i == find(i)) {
            block_cnt++;
        }
    }
    if (D < block_cnt) {
        cout << "NO\n";
        return;
    }

    vector<PII> edges;
    set<int> used;
    set<int> next_visit;
    vis[1] = true;
    for (auto v : e[1]) {
        int fav = find(v);
        if (!used.count(fav)) {
            used.insert(fav);
            edges.pb({1, v});
            next_visit.insert(v);
            vis[v] = true;
        }
    }
    for (auto v : e[1]) {
        if (next_visit.size() >= D) {
            break;
        }
        if (!next_visit.count(v)) {
            next_visit.insert(v);
            edges.pb({1, v});
            vis[v] = true;
        }
    }
    for (auto u : next_visit) {
        dfs(u, edges);
    }
    cout << "YES\n";
    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i].x << " " << edges[i].y << "\n";
    }
}                                                                                                                  
