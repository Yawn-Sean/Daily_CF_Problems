/*
似乎要用到最短路径图，先求最短路，以及每个最短路的前驱
最短路径图中，每个点都是最短的 d，所以从中取出一个最短路径树一定是符合题意的
不是最短路径树是否可行？不行，因为有一个大了就得有更小的，但不可能更小了
如何计数最短路径树的个数？
对于 1 个点来说，其肯定得选一个最短路前驱
而那个前驱为了保证自己也是最短路，所以也得选 1 个最短路前驱，一直这样下去，就到了 1
所以只要每个点看自己有几个最短路前驱，根据乘法原理就可以知道有多少符合题意了
输出方案，只需要先求最短路，然后递归，枚举 2-n，每个点枚举最短路前驱边，递归到 n + 1 就输出
*/

LL n, m, k;
vector<vector<int>> e(N);
vector<vector<int>> pre(N);
map<LL, int> edge_id;
LL d[N], choose[N], print_cnt = 0;

void bfs(int st) {
    bool vis[N] = {false};
    queue<int> q;
    q.push(st);
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    vis[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : e[u]) {
            if (d[v] == d[u] + 1) {
                pre[v].pb(u);
            } else if (d[v] > d[u] + 1) {
                pre[v].clear();
                pre[v].pb(u);
                d[v] = d[u] + 1;
            }
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void dfs(int u, LL target) {
    if (u == n + 1) {
        if (print_cnt >= target) {
            return;
        }
        for (int i = 1; i <= m; i++) {
            cout << choose[i];
        }
        cout << "\n";
        print_cnt++;
        return;
    }

    for (auto &v : pre[u]) {
        if (print_cnt >= target) {
            return;
        }
        LL vv = v, uu = u;
        if (uu > vv) {
            swap(uu, vv);
        }
        LL id = edge_id[uu * N + vv];
        choose[id] = 1;
        dfs(u + 1, target);
        choose[id] = 0;
    }
}

void meibao() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        LL u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        if (u > v) {
            swap(u, v);
        }
        edge_id[u * N + v] = i;
    }
    bfs(1);
    LL cnt = 1;
    for (int i = 2; i <= n; i++) {
        cnt *= pre[i].size();
        if (cnt >= k) {
            break;
        }
    }
    LL target = min(cnt, k);
    cout << target << "\n";
    dfs(2, target);
}   
