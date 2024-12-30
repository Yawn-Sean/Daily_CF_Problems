int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<pii>> g(n);
    vector<vector<pii>> g1(n);
    while (m --) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        x --, y --;
        g[x].emplace_back(y, (s[0] == 'i'));
        g1[y].emplace_back(x, (s[0] == 'i'));
    }
    
    vector<bool> seen(n, false);
    vector<int> st(n, -1);
    
    auto bfs = [&](int u, int val) {
        vector<int> ver;
        queue<int> q;
        q.push(u);
        st[u] = val;
        ver.push_back(u);
        bool ok = true;
        
        while (!em(q)) {
            auto t = q.front();
            q.pop();
            for (auto [x, k] : g[t]) {
                if (st[x] == -1) {
                    st[x] = st[t] ^ k;
                    q.push(x);
                    ver.push_back(x);
                }
                else if (st[x] != (st[t] ^ k)) {
                    ok = false;
                }
            }
            for (auto [x, k] : g1[t]) {
                // st[x] ^ k = st[t]
                if (st[x] == -1) {
                    st[x] = st[t] ^ k;
                    q.push(x);
                    ver.push_back(x);
                }
                else if (st[x] != (st[t] ^ k)) {
                    ok = false;
                }
            }
        }
        int res = 0;
        for (auto x : ver) {
            seen[x] = true;
            res += (st[x] == 0);
            st[x] = -1;
        }
        return (ok ? res : -inf);
    };
    int res = 0;
    for (int i = 0; i < n; i ++) {
        if (seen[i]) continue;
        res += max(bfs(i, 0), bfs(i, 1));
    }
    cout << (res < 0 ? -1 : res) << endl;
}