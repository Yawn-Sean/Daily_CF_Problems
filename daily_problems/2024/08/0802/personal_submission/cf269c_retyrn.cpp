int n, m;
using ai4 = array<int, 4>;

void solve() {
    cin >> n >> m;
    vector<vector<ai4>> g(n);
    vector<int> f(n);
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        a --, b --;
        g[a].push_back({b, c, i, 0});
        g[b].push_back({a, c, i, 1});
        f[a] += c;
        f[b] += c;
    }
    for (auto& x : f) {
        x >>= 1;
    }
    
    queue<int> q;
    q.push(0);
    
    vector<int> res(m, -1);
    
    while (!em(q)) {
        auto ver = q.front();
        q.pop();
        for (auto [x, w, id, u] : g[ver]) {
            if (res[id] == -1) {
                res[id] = u;
                f[x] -= w;
                if (x < n - 1 and f[x] == 0) {
                    q.push(x);
                }
            }
        }
    }
    
    for (auto x : res) {
        cout << x << endl;
    }
}