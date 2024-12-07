int n, m;
using ai3 = array<int, 3>;

void solve() {
    cin >> n >> m;
    vector<vector<pii>> g(n);
    
    while (m --) {
        int x, y, w;
        cin >> x >> y >> w;
        x --, y --;
        g[x].emplace_back(y, w);
        g[y].emplace_back(x, w);
    }
    
    vector<int> st(n, false);
    vector<double> res(n);
    vector<int> ks(n), bs(n);
    // 假设初始点是x, 每个点可以表示成 kx+b 的形式
    
    auto gao = [&](int root) -> bool {
        double x = 0.0;
        bool ok = false;
        queue<int> q;
        st[root] = true;
        q.push(root);
        ks[root] = 1, bs[root] = 0;
        vector<int> v;
        
        while (!em(q)) {
            auto t = q.front();
            q.pop();
            v.push_back(t);
            for (auto [nx, w] : g[t]) {
                int need_k = -ks[t], need_b = w - bs[t];
                if (!st[nx]) {
                    st[nx] = true;
                    ks[nx] = need_k, bs[nx] = need_b;
                    q.push(nx);
                }
                else {
                    if (need_k == ks[nx]) {
                        if (need_b == bs[nx]) continue;
                        return false;
                    }
                    // need_k * x + need_b == ks[nx] * b + bs[nx]
                    // (need_k - ks[nx]) * x == bs[nx] - need_b
                    double need_x = 1.0 * (bs[nx] - need_b) / (need_k - ks[nx]);
                    if (ok and fabs(need_x - x) > eps) return false;
                    if (!ok) x = need_x, ok = true;
                }
            }
        }
        
        if (!ok) {
            // 取中位数
            vector<int> nums;
            for (auto ver : v) {
                if (ks[ver] < 0) nums.push_back(bs[ver]);
                else nums.push_back(-bs[ver]);
            }
            sort(all(nums));
            x = nums[sz(nums) / 2];
        }

        for (auto ver : v) {
            res[ver] = x * ks[ver] + bs[ver];
        }
        return true;
    };
    
    for (int i = 0; i < n; i ++) {
        if (st[i]) continue;
        if (!gao(i)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    cout << res << endl;
}