/*
求有序对 (u, v)，从 u 走到 v 时不能先经过 x 再经过 y
考虑 x 往不向 y 的那个方向遍历，y 往不向 x 的那个方向遍历
x 能遍历到 cnt1 个点，y 能遍历到 cnt2 个点，则这 cnt1 * cnt2 对肯定不行
其他别的对都行
*/

vector<vector<int>> e(N);
LL n, x, y;
vector<int> path;
bool finished = false;

void get_path(int u, int fa) {
    path.push_back(u);
    if (u == y) {
        finished = true;
        return;
    }
    for (auto v : e[u]) {
        if (finished) {
            return;
        }
        if (v != fa) {
            get_path(v, u);
        }
    }
    if (finished) {
        return;
    }
    path.pop_back();
}

LL dfs(int u, int fa) {
    LL res = 1;
    for (auto v : e[u]) {
        if (v != fa) {
            res += dfs(v, u);
        }
    }
    return res;
}

void meibao() {
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    get_path(x, 0);
    assert(path.size() >= 2);
    int fx = path[1], fy = path[path.size() - 2];
    LL cnt1 = dfs(x, fx), cnt2 = dfs(y, fy);
    cout << n * (n - 1) - cnt1 * cnt2 << "\n";
}
