/*
考虑把被封锁的边建起来
后边如果要删两个点，则相当于把这两个点的邻边全部加到补图里
那么原图中度数 <= 1，意味着补图里度数 >= n - 2
如果只要求删一个点，会不会好做一些？
假设一个点都不删的时候，答案是 base_ans
删掉某个点 u 时，我们其实关心这个 u 点连的点里面，有多少个在补图里的度数恰好是 n - 3
删了 u 之后，这些点在补图里的度数都 + 1，之前是 n - 3 的会变成 n - 2，变得符合要求了
然后 u 之前如果也是符合题意的，就要答案里减去 1

如何快速看 u 在原图中的邻点中，有多少个在补图里的度数恰好是 n - 3 呢？
我们注意到一个事情，补图里的度数之和是 2m，删除了 2 个点之后度数之和至多是 2m + 2n
当 n 比较大的时候，补图里不会有多少点的度数 >= n - 3，我们直接枚举度数 = n - 3 的点，看是否和 u 邻接即可
大概需要枚举 O(2m / n) 个点
当 n 比较小的时候，我们可以暴力枚举 u 的邻点，然后看度数，大概需要枚举 O(n) 个点
想让 n 和 2m / n 都较小，则取 border = sqrt(2m)
当 n <= border 的时候枚举 u 的邻点，至多枚举 O(border) 个点，然后答案也就出来了
n > border 的时候就直接枚举度数 = n - 3 的点，至多枚举 O(border) 个点，答案也出来了

对于删两个点的情况，容斥就好了
我们先算 u 点邻接的补图里度数为 n - 3 的点，全都求出来，s1
再算 v 点邻接的补图里度数为 n - 3 的点，全都求出来，s2
s1 和 s2 做并集，就是度数为 n - 3 的点的贡献
然后我们还要看 u 点邻接的补图里度数为 n - 4 的点，全都求出来，s3
v 点邻接的补图里度数为 n - 4 的点，全都求出来，s4
s3 和 s4 做交集，就是度数为 n - 4 的点的贡献
最后记得把 u 和 v 去掉
*/ 

const int N = 2e5 + 10;

int n, m, q, deg[N];
vector<vector<int>> e(N);
// nodes[i] 表示补图中度数为 n - i 的点的集合
vector<vector<int>> nodes(5);

inline bool check_edge(int u, int node) {
    return binary_search(e[u].begin(), e[u].end(), node);
}

bool ban_u[N], ban_v[N];

void calc1(int u, int v) {
    // 先贡献操作前补图中度数为 n - 1 和 n - 2 的点
    int res = nodes[1].size() + nodes[2].size();

    if (deg[u] >= n - 2) {
        res--;
    }
    if (deg[v] >= n - 2) {
        res--;
    }

    for (auto node : e[u]) {
        ban_u[node] = true;
    }
    ban_u[u] = true;

    for (auto node : e[v]) {
        ban_v[node] = true;
    }
    ban_v[v] = true;

    // 贡献补图中度数为 n - 3 的点
    vector<int> vis1(n + 1, 0), vis2(n + 1, 0);
    for (int node = 1; node <= n; node++) {
        if (ban_u[node]) {
            continue;
        }
        if (deg[node] == n - 3 && node != v) {
            vis1[node] = 1;
        }
    }
    for (int node = 1; node <= n; node++) {
        if (ban_v[node]) {
            continue;
        }
        if (deg[node] == n - 3 && node != u) {
            vis2[node] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis1[i] || vis2[i]) {
            res++;
        }
    }

    // 贡献补图中度数为 n - 4 的点
    vector<int> vis3(n + 1, 0), vis4(n + 1, 0);
    for (int node = 1; node <= n; node++) {
        if (ban_u[node]) {
            continue;
        }
        if (deg[node] == n - 4 && node != v) {
            vis3[node] = 1;
        }
    }
    for (int node = 1; node <= n; node++) {
        if (ban_v[node]) {
            continue;
        }
        if (deg[node] == n - 4 && node != u) {
            vis4[node] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis3[i] && vis4[i]) {
            res++;
        }
    }

    // 清理打标记的普通数组，准备下一次查询
    for (auto node : e[u]) ban_u[node] = false;
    ban_u[u] = false;
    for (auto node : e[v]) ban_v[node] = false;
    ban_v[v] = false;

    cout << res << "\n";
}

void calc2(int u, int v) {
    // 先贡献操作前补图中度数为 n - 1 和 n - 2 的点
    int res = nodes[1].size() + nodes[2].size();

    if (deg[u] >= n - 2) {
        res--;
    }
    if (deg[v] >= n - 2) {
        res--;
    }

    // 贡献补图中度数为 n - 3 的点
    for (auto node : nodes[3]) {
        if (node == u || node == v) continue;
        int c1 = check_edge(u, node), c2 = check_edge(v, node);
        if (c1 == 0 || c2 == 0) {
            res++;
        }
    }

    // 贡献补图中度数为 n - 4 的点
    for (auto node : nodes[4]) {
        if (node == u || node == v) continue;
        int c1 = check_edge(u, node), c2 = check_edge(v, node);
        if (c1 == 0 && c2 == 0) {
            res++;
        }
    }
    cout << res << "\n";
}

void solve() {
    cin >> n >> m >> q;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= n; i++) {
        sort(e[i].begin(), e[i].end());
    }

    for (int i = 1; i <= n; i++) {
        int idx = n - deg[i];
        if (idx <= 4) {
            nodes[idx].push_back(i);
        }
    }

    int border = 100;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (n <= border) {
            calc1(u, v);
        } else {
            calc2(u, v);
        }
    }
}
