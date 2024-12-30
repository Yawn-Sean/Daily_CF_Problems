int n, m, s, t;

vector<int> bfs(vector<vector<int>>& g, int start) {
    vector<int> dis(n, inf);
    queue<int> q;
    dis[start] = 0;
    q.push(start);
    while (!em(q)) {
        auto ver = q.front();
        q.pop();
        for (auto x : g[ver]) {
            if (dis[x] == inf) {
                dis[x] = dis[ver] + 1;
                q.push(x);
            }
        }
    }
    return dis;
}

void solve() {
    cin >> n >> m >> s >> t;
    s --, t --;
    
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    vector<int> d1 = bfs(g, s);
    vector<int> d2 = bfs(g, t);
    int distance = d1[t];
    
    int res = n * (n - 1) / 2 - m;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (d1[i] + d2[j] + 1 < distance or d2[i] + d1[j] + 1 < distance) {
                res -= 1;
            }
        }
    }
    cout << res << endl;
}