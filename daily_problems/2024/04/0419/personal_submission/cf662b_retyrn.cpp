using ai3 = array<int, 3>;
int n, m;
vector<vector<pii>> g;
vector<vector<int>> con;
vector<vector<ai3>> cone;
int choose[maxn], st[maxn];

bool check(vector<ai3>& e, int u) {
    for (auto [x, y, w] : e) {
        if ((choose[x] ^ choose[y] ^ w) != u) return false;
    }
    return true;
}

int bfs(vector<int>& v, vector<ai3>& e, vector<int>& select, int u, int op) {
    for (auto x : v) {
        choose[x] = st[x] = 0;
    }
    queue<int> q;
    q.push(v[0]);
    choose[v[0]] = op;
    st[v[0]] = 1;
    
    while (!em(q)) {
        auto t = q.front();
        q.pop();
        for (auto [x, w] : g[t]) {
            if (st[x]) continue;
            choose[x] = (w ^ u ^ choose[t]);
            st[x] = 1;
            q.push(x);
        }
    }
    
    // check
    if (!check(e, u)) {
        return -1;
    }
    for (auto x : v) {
        if (choose[x]) select.pbk(x + 1);
    }
    return sz(select);
}

void solve() {
    cin >> n >> m;
    g.resize(n);
    while (m --) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        int u = (s[0] == 'B' ? 0 : 1);
        a --, b --;
        g[a].pbk(mpr(b, u));
        g[b].pbk(mpr(a, u));
    }
    
    vector<bool> st(n, false);
    
    function<void(vector<int>&, int)> dfs = [&](vector<int>& p, int u) {
        st[u] = true;
        p.push_back(u);
        for (auto [x, _] : g[u]) {
            if (st[x]) continue;
            dfs(p, x);
        }
    };
    
    for (int i = 0; i < n; i ++) {
        if (st[i]) continue;
        vector<int> layer;
        vector<ai3> edge;
        dfs(layer, i);
        con.pbk(layer);
        for (auto x : layer) {
            for (auto [y, w] : g[x]) {
                edge.pbk({x, y, w});
            }
        }
        cone.pbk(edge);
    }
    
    
    int res = inf;
    vector<int> path;
    
    for (int i = 0; i < 2; i ++) {
        int ans = 0;
        vector<int> p;
        for (int j = 0; j < sz(con); j ++) {
            // 不选第一个点
            vector<int> v0, v1;
            auto t0 = bfs(con[j], cone[j], v0, i, 0);
            auto t1 = bfs(con[j], cone[j], v1, i, 1);
            
            if (t0 < 0 and t1 < 0) {
                ans = inf;
                break;
            }
            if (t0 >= 0 and t1 >= 0) {
                if (t0 < t1) {
                    ans += t0;
                    for (auto x : v0) p.pbk(x);
                }
                else {
                    ans += t1;
                    for (auto x : v1) p.pbk(x);
                }
            }
            else if (t0 >= 0) {
                ans += t0;
                for (auto x : v0) p.pbk(x);
            }
            else {
                ans += t1;
                for (auto x : v1) p.pbk(x);
            }
        }
        if (ans < inf / 2 and ans < res) {
            res = ans;
            path = move(p);
        }
    }
    
    if (res >= inf / 2) {
        cout << -1 << endl;
        return;
    }
    cout << res << endl;
    cout << path << endl;
}
