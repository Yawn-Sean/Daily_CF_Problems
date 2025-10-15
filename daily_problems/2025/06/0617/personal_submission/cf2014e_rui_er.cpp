const ll N = 4e5 + 5, inf = 0x3f3f3f3f3f3f3f3fll;

ll T, n, m, h, a[N], dis[2][N], vis[N];
vector<tuple<ll, ll>> e[N];

void dijkstra(ll* dis, ll s) {
    rep(i, 1, n + n) {
        dis[i] = +inf;
        vis[i] = 0;
    }
    priority_queue<tuple<ll, ll>> heap;
    dis[s] = 0;
    heap.emplace(-dis[s], s);
    while(!heap.empty()) {
        ll u = get<1>(heap.top()); heap.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto [v, w]: e[u]) {
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                heap.emplace(-dis[v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n >> m >> h;
        rep(i, 1, h) {
            cin >> a[i];
            e[a[i]].emplace_back(n + a[i], 0);
        }
        rep(i, 1, m) {
            ll u, v, w;
            cin >> u >> v >> w;
            e[u].emplace_back(v, w);
            e[v].emplace_back(u, w);
            e[n + u].emplace_back(n + v, w / 2);
            e[n + v].emplace_back(n + u, w / 2);
        }
        dijkstra(dis[0], 1);
        dijkstra(dis[1], n);
        ll ans = +inf;
        rep(i, 1, n) {
            ll ds = min(dis[0][i], dis[0][n + i]);
            ll dt = min(dis[1][i], dis[1][n + i]);
            chkmin(ans, max(ds, dt));
        }
        cout << (ans == +inf ? -1LL : ans) << endl;
        // clear
        rep(i, 1, n + n) e[i].clear();
    }
    return 0;
}
