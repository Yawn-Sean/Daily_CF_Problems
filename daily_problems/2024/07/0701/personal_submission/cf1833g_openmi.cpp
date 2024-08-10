void solve() {
    int n;
    cin >> n;
    vector<vector<int>> path(n);
    // 存读入的左端点和读入的右端点
    vector<int> v_u, v_v;
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        v_u.push_back(u);
        v_v.push_back(v);
        path[u].push_back(i);
        path[v].push_back(i);
    }
 
    int mx_deep = 0;
    vi deep(n), pa(n);
    // 按深度存点
    vc<vi> dg(n);
 
    auto dfs = [&](auto&& dfs, int u, int fa)->void {
        pa[u] = fa;
        chmax(mx_deep, deep[u]);
        dg[deep[u]].push_back(u);
        for (int i: path[u]) {
            // 无需min、max区分点，异或出来
            int v = v_u[i] ^ v_v[i] ^ u;
            if (v == fa) continue;
            deep[v] = deep[u] + 1;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 0, -1); 
    if (n % 3) { cout << -1 << nl; return; }
 
    // ct 局部branches个数
    vi ct(n, 1), ans;
    // 以 0 为根，从底部叶子节点向上凑；
    // 没有深度的话, 图中部分的叶子节点的父亲有多个子点时，无法确定与谁合并
    while (mx_deep) {
        for (int u: dg[mx_deep]) {       
            for (int i: path[u]) {
                int v = v_u[i] ^ v_v[i] ^ u;
                if (ct[v] == 0) continue;
                // 每次形成branches就从跟父节点连接的边处断开
                if (ct[u] == 3 and v == pa[u]) {
                    ans.push_back(i + 1);
                } else {
                    ct[v] += ct[u];
                    ct[u] = 0;
                }
            }
            if (ct[u] == 3) ct[u] = 0;
        }
        mx_deep--;
    }
 
    if ((ans.size() + 1) * 3 != n) { cout << -1 << nl; return; }
    cout << ans.size() << nl;
    printv(ans, ' ', false);
}
