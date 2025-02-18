using ai3 = array<int, 3>;
int n, m;
vector<vector<int>> g;
vector<bool> st;

pii dfs(int u, int fa, ai3& ans) {
    st[u] = true;
    pii d1 = {0, u}, d2 = {0, u};
    for (auto x : g[u]) {
        if (x == fa) continue;
        auto t = dfs(x, u, ans);
        if (t.fi > d1.fi) d2 = d1, d1 = t;
        else if (t.fi > d2.fi) d2 = t;
    }
    if (ans[0] < d1.fi + d2.fi) {
        ans[0] = d1.fi + d2.fi;
        ans[1] = d1.se;
        ans[2] = d2.se;
    }
    d1.fi += 1;
    return d1;
}

void bfs(vector<int>& d, int u) {
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while (!em(q)) {
        auto t = q.front();
        q.pop();
        for (auto x : g[t]) {
            if (d[x] == inf) {
                d[x] = d[t] + 1;
                q.push(x);
            }
        }
    }
}

pii get_diameter(int u) {
    ai3 ans = {-1, -1, -1};
    dfs(u, -1, ans);
    
    int dia = ans[0], who1 = ans[1], who2 = ans[2];
    vector<int> d1(n, inf), d2(n, inf);
    bfs(d1, who1);
    bfs(d2, who2);
    int who = -1;
    for (int i = 0; i < n; i ++) {
        if (d1[i] + d2[i] == dia and (d1[i] == (dia + 1) / 2 or d2[i] == (dia + 1) / 2)) {
            who = i;
            break;
        }
    }
    return mpr(dia, who);
}

void solve() {
    cin >> n >> m;
    g.resize(n);
    st.resize(n);
    
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].pbk(y);
        g[y].pbk(x);
    }
    
    priority_queue<pii> q;
    
    for (int i = 0; i < n; i ++) {
        if (st[i]) continue;
        auto t = get_diameter(i);
        q.push(t);
    }
    
    vector<pii> res;
    
    while (sz(q) > 1) {
        auto [d1, who1] = q.top();
        q.pop();
        auto [d2, who2] = q.top();
        q.pop();
        res.pbk(mpr(who1+1, who2+1));
        g[who1].pbk(who2);
        g[who2].pbk(who1);
        auto cur = get_diameter(who1);
        q.push(cur);
    }
    
    cout << q.top().fi << endl;
    for (auto [x, y] : res) {
        cout << x << ' ' << y << endl;
    }
}