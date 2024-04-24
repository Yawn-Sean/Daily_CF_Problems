int n, m;
using ai3 = array<int, 3>;

void solve() {
    // 考虑每条边的贡献
    // 除了三点在同一侧 每个情况都有2个贡献
    cin >> n;
    vector<vector<pii>> g(n);
    vector<int> size(n), fa(n, -1);
    vector<ai3> E(n - 1);
    
    for (int i = 0; i < n - 1; i ++) {
        int x, y, w;
        cin >> x >> y >> w;
        x --, y --;
        g[x].pbk({y, w});
        g[y].pbk({x, w});
        E[i][0] = x, E[i][1] = y, E[i][2] = w;
    }
    
    function<void(int u)> dfs = [&](int u) {
        size[u] = 1;
        for (auto [x, _] : g[u]) {
            if (x == fa[u]) continue;
            fa[x] = u;
            dfs(x);
            size[u] += size[x];
        }
    };
    
    dfs(0);
    
    auto cal = [&](int son, double w) {
        int s1 = size[son], s2 = n - s1;
        return w * s1 * (s1 - 1) * s2 + w * s2 * (s2 - 1) * s1;
    };
    
    double sum = 0.0;
    for (auto& e : E) {
        int &x = e[0], &y = e[1];
        if (fa[x] == y) swap(x, y); // 始终让x是y的父节点
        sum += cal(y, e[2]);
    }
    
    cin >> m;
    while (m --) {
        int id, val;
        cin >> id >> val;
        id --;
        sum -= cal(E[id][1], E[id][2]);
        sum += cal(E[id][1], val);
        E[id][2] = val;
        cout << (sum * 6 / n / (n - 1) / (n - 2)) << endl;
    }
    
}