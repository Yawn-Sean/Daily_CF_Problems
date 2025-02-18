using pli = pair<ll, int>;
using ai3 = array<int, 3>;
int n, m, k;

void dijkstra(vector<vector<ai3>>& g, vector<ll>& dist) {
    vector<bool> st(n, false);
    dist[0] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> heap;
    heap.push({0, 0});

    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;
        ll distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (auto [j, w, _] : g[ver]) {
            if (dist[j] > distance + w) {
                dist[j] = distance + w;
                heap.push({dist[j], j});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    vector<vector<ai3>> g(n);
    for (int i = 0; i < m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        a --, b --;
        g[a].push_back({b, c, i + 1});
        g[b].push_back({a, c, i + 1});
    }
    
    // dijkstra
    vector<ll> dist(n, inf2);
    dijkstra(g, dist);
    
    // 只保留一个树形结构
    vector<int> res;
    queue<int> q;
    vector<int> st(n);
    st[0] = 1;
    q.push(0);
    
    while (!em(q) and sz(res) < k) {
        auto ver = q.front();
        q.pop();
        for (auto [x, w, id] : g[ver]) {
            if (st[x]) continue;
            if (dist[x] - dist[ver] == w) {
                st[x] = 1;
                q.push(x);
                res.push_back(id);
            }
            if (sz(res) >= k) break;
        }
    }
    
    cout << sz(res) << endl;
    cout << res << endl;
}