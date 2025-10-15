const int N = 2e5 + 5, inf = 0x3f3f3f3f;

int n, t, k, a[N], dis[N], vis[N];
vector<tuple<int, int>> e[N];
vector<int> d[N];

void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<tuple<int, int>> heap;
    dis[s] = 1;
    heap.emplace(-dis[s], s);
    while(!heap.empty()) {
        int u = get<1>(heap.top()); heap.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto [v, t]: e[u]) {
            int w = 1 + *lower_bound(d[t].begin(), d[t].end(), dis[u]);
            if(dis[v] > w) {
                dis[v] = w;
                heap.emplace(-dis[v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> t;
    rep(i, 1, t) {
        int m;
        cin >> m;
        rep(j, 1, m) {
            int u, v;
            cin >> u >> v;
            e[u].emplace_back(v, i);
            e[v].emplace_back(u, i);
        }
    }
    cin >> k;
    rep(i, 1, k) {
        cin >> a[i];
        d[a[i]].push_back(i);
    }
    rep(i, 1, t) d[i].push_back(+inf);
    dijkstra(1);
    cout << (dis[n] == +inf ? -1 : dis[n] - 1) << endl;
    return 0;
}
