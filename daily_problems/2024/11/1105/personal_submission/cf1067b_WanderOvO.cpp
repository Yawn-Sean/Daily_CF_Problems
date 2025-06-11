/*
从一个点出发，往外连至少 3 个点，就是刺猬
k 阶刺猬就是从 k - 1 阶刺猬的度为 1 的点，以其为中心，往外连至少 3 个度为 1 的点
假设我们知道起始点，如何判断是否是刺猬？如何计算刺猬的阶数？
首先判断是否连了 >= 3 个别的点，是的话就可以递归判断剩下的部分
1 个点连的其他点（除了父亲），要么度都不是 1，要么都是 1
都是 1 则可以看距离了，假如距离不是 k 则不是刺猬
假如不都是 1，则肯定不是刺猬
如何找到中心点？似乎是找直径的中点
从中心点到每个叶子的距离都相等，并且这样拼出来肯定是直径
*/

int n, k, d[N], dist[3][N];
vector<vector<int>> e(N);
vector<int> nodes;

void dfs(int u, int fa, int depth, int dist[]) {
    dist[u] = depth;
    for (auto v : e[u]) {
        if (v != fa) {
            dfs(v, u, depth + 1, dist);
        }
    }
}

int find_root(int u, int fa, int max_len) {
    nodes.pb(u);
    if (dist[2][u] == max_len) {
        return nodes[max_len / 2];
    }
    int res = -1;
    for (auto v : e[u]) {
        if (v != fa) {
            res = max(res, find_root(v, u, max_len));
            if (res > 0) {
                return res;
            }
        }
    }
    nodes.pop_back();
    return res;
}

bool check(int u, int fa) {
    int deg = d[u] - (fa != 0 ? 1 : 0);
    if (deg < 3) {
        return false;
    }
    bool has_one = false, has_other = false;
    for (auto v : e[u]) {
        if (v != fa) {
            if (d[v] == 1) {
                has_one = true;
            } else {
                has_other = true;
            }
        }
    }
    if (has_one && has_other) {
        return false;
    }
    if (has_one) {
        if (dist[0][u] + 1 != k) {
            return false;
        }
        return true;
    }
    assert(has_other);
    bool res = true;
    for (auto v : e[u]) {
        if (v != fa) {
            res = (res && check(v, u));
        }
    }
    return res;
}

void meibao() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        d[v]++;
        d[u]++;
    }
    dfs(1, 0, 0, dist[1]);
    int mx = 0, mx_v = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[1][i] > mx) {
            mx = dist[1][i];
            mx_v = i;
        }
    }
    dfs(mx_v, 0, 0, dist[2]);
    int max_len = 0;
    for (int i = 1; i <= n; i++) {
        max_len = max(max_len, dist[2][i]);
    }
    // cout << max_len << "\n";
    if (max_len % 2 != 0) {
        cout << "No\n";
        return;
    }
    int root = find_root(mx_v, 0, max_len);
    // cout << root << "\n";
    dfs(root, 0, 0, dist[0]);
    cout << (check(root, 0) ? ("Yes") : ("No")) << "\n";
}
