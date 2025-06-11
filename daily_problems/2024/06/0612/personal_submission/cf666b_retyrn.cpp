int n, m;

void bfs(vector<vector<int>>& g, vector<int>& dis, int start) {
    queue<int> q;
    dis[start] = 0;
    q.push(start);
    
    while (sz(q)) {
        auto t = q.front();
        q.pop();
        for (auto x : g[t]) {
            if (dis[x] == inf) {
                dis[x] = dis[t] + 1;
                q.push(x);
            } 
        }
    }
}

void get(vector<int>& dis, vector<int>& res, int len) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 0; i < n; i ++) {
        if (dis[i] >= inf / 2) continue;
        q.push(mpr(dis[i], i));
        while (sz(q) > len) {
            q.pop();
        }
    }
    while (!em(q)) {
        res.push_back(q.top().se);
        q.pop();
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> g1(n), g2(n);
    while (m --) {
        int a, b;
        cin >> a >> b;
        a --, b --;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    
    vector<vector<int>> dis1(n, vector<int>(n, inf));
    vector<vector<int>> dis2(n, vector<int>(n, inf));
    // 预处理距离
    for (int i = 0; i < n; i ++) {
        bfs(g1, dis1[i], i);
        bfs(g2, dis2[i], i);
    }
    vector<vector<int>> w1(n), w2(n);
    
    for (int i = 0; i < n; i ++) {
        get(dis1[i], w1[i], 4);
        get(dis2[i], w2[i], 4);
    }
    
    vector<int> res(4);
    int mx = 0;
    // 枚举中间两个
    for (int b = 0; b < n; b ++) {
        for (int c = 0; c < n; c ++) {
            if (b == c or dis1[b][c] >= inf / 2) continue;
            vector<int>& A = w2[b];
            vector<int>& D = w1[c];
            for (auto a : A) {
                if (a == b or a == c) continue;
                for (auto d : D) {
                    if (a == d or b == d or c == d) continue;
                    if (mx < dis1[a][b] + dis1[b][c] + dis1[c][d]) {
                        res[0] = a + 1, res[1] = b + 1, res[2] = c + 1, res[3] = d + 1;
                        mx = dis1[a][b] + dis1[b][c] + dis1[c][d];
                    }
                }
            }
        }
    }
    cout << res << endl;
}