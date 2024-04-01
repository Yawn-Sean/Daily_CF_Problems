int T;
int n, a[N], c[N], d[N];
vector<int> son[N];
bool vis[N];

// 度 > 0 的是环上的点
void toposort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < son[u].size(); i++) {
            int v = son[u][i];
            d[v]--;
            if (d[v] == 0) {
                q.push(v);
            }
        }
    }
}

void getRingNodes(int u, vector<int> &ringNodes) {
    ringNodes.push_back(u);
    vis[u] = true;
    for (auto v : son[u]) {
        if (vis[v]) {
            return;
        }
        
        // 是环上的点
        if (d[v] != 0) {
            getRingNodes(v, ringNodes);
        }
    }
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        son[i].pb(a[i]);
        d[a[i]]++;
    }
    
    LL res = 0;
    toposort();
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && d[i] > 0) {
            vector<int> ringNodes;
            getRingNodes(i, ringNodes);
            int mn = 1e5;
            for (auto u : ringNodes) {
                mn = min(mn, c[u]);
            }
            res += mn;
        }
    }
    cout << res << "\n";
}  