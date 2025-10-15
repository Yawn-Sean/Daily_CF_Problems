/*
操作：
1.  y 是 x 的老板，题目保证 x 只会连一条出边，且无循环依赖
2. 给 x 一个文件，x 签完之后给其指向的 y... 一直到无法进行为止
3. 询问 x 是否签过某个文件
每个人保存自己签了哪些文件并不现实，空间都不够
对于 x，记录其签了哪个文件，以及签这个文件时往上走了多少次
查询 y 是否签了某个文件 i 时，可以先找 i 最开始是从 x 开始签的，然后检查 y 和 x 的父子关系与距离
如何计算往上走了多少次？
预先把整个树建出来，记录每条边的创建时间，再倍增预处理一下创建时间的最大值
进行操作 2 时，二分到底能往上走多少次，然后倍增往上跳，看创建时间最大值是否在该操作之前
进行操作 3 时，检查两个点是否连通，lca 是不是被查的那个人，并且看距离有没有超
*/

struct Operation {
    int t, x, y, i;
};

struct Edge {
    int v, time;
};

Operation ops[N];
int n, m, fa[N][M], max_time[N][M], depth[N], document_idx = 0, lg[N];
int p[N];
bool vis[N];
int first_received[N], cnt[N];
vector<vector<Edge>> e(N);

int find(int x) {
    if (x == p[x]) {
        return x;
    }
    return p[x] = find(p[x]);
}

bool together(int x, int y) {
    return find(x) == find(y);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    p[x] = y;
}

void dfs(int u, int father, int t) {
    vis[u] = true;
    depth[u] = depth[father] + 1;
    fa[u][0] = father;
    max_time[u][0] = t;
    int d = depth[u];
    for (int i = 1; i <= lg[d]; i++) {
        int f = fa[u][i - 1];
        fa[u][i] = fa[f][i - 1];
        max_time[u][i] = max(max_time[u][i - 1], max_time[f][i - 1]);
    }
    for (auto &edge : e[u]) {
        if (edge.v != father) {
            dfs(edge.v, u, edge.time);
        }
    }
}

bool check(int length, int u, int t) {
    if (depth[u] < length) {
        return false;
    }
    length--;
    int mx = 0;
    for (int i = M; i >= 0; i--) {
        if ((length >> i) & 1) {
            mx = max(mx, max_time[u][i]);
            u = fa[u][i];
        }
    }
    return mx <= t;
}

int get_cnt(int u, int t) {
    int l = 1, r = n, mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check(mid, u, t)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (check(r, u, t)) {
        return r;
    }
    return l;
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    while (depth[x] > depth[y]) {
        x = fa[x][lg[depth[x] - depth[y]]];
    }
    if (x == y) {
        return x;
    }
    for (int i = lg[depth[x]]; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        depth[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> ops[i].t;
        if (ops[i].t == 1) {
            cin >> ops[i].x >> ops[i].y;
            Edge edge;
            edge.v = ops[i].x;
            edge.time = i;
            e[ops[i].y].push_back(edge);
            depth[ops[i].x] += depth[ops[i].y];
        } else if (ops[i].t == 2) {
            cin >> ops[i].x;
        } else {
            cin >> ops[i].x >> ops[i].i;
        }
    }
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && depth[i] == 1) {
            dfs(i, 0, INF);
        }
    }

    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        if (ops[i].t == 1) {
            merge(ops[i].x, ops[i].y);
        } else if (ops[i].t == 2) {
            first_received[++document_idx] = ops[i].x;
            cnt[document_idx] = get_cnt(ops[i].x, i);
        } else if (ops[i].t == 3) {
            int first_receiver = first_received[ops[i].i];
            int target = ops[i].x;
            if (together(target, first_receiver) && lca(target, first_receiver) == target && depth[first_receiver] - depth[target] + 1 <= cnt[ops[i].i]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
